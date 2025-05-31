#include "environment.h"
#include "genericRobot.h"
#include "stage1Upgrades/bombBot.h"
#include "stage1Upgrades/upgrades.h"
#include "vector2d.h"

#include <memory>
#include <sstream>
#include "upgradeBots.h"

// Needed for sleep function
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

const char* BLUE_COLOR = "\033[34m";
const char* RESET_COLOR = "\033[0m";
const char* ORANGE_COLOR = "\033[33m";
const char* RED_COLOR = "\033[31m";

Environment::Environment(
    int maxStep,
    Vector2D dimension,
    vector<RobotParameter> robotParams,
    Logger* logger
) {
    this->maxStep = maxStep;
    this->dimension = dimension;

    // Initialize grid for marks ('.' means empty)
    grid.resize(dimension.x, vector<char>(dimension.y, '.'));

    this->logger = logger;

    // By default, C++ store objects on the stack memory
    // Every time an object goes out-of-scope (here, on each loop iteration), it will be destroyed
    // Using raw pointers, all the robots that are created will be destroyed except the last one.
    //
    // To avoid that you have to store them on the heap memory (using the 'new' keyword)
    // Problem with that is we have to 'delete' the objects afterwards
    // which is a massive pain in the ass.
    //
    // Instead, we are going to use 'smart pointers' (here, it is unique_ptr)
    // It will automatically 'delete' our object when the program ends.
    //
    // Note that unique_ptr also means that Environment now 'owns' the robots object
    // Important note for later.
    for (const RobotParameter &param : robotParams) {
        GenericRobot* robot = new GenericRobot(param, this, logger);

        this->robotList.push_back(unique_ptr<GenericRobot>(robot));
    }
}

void Environment::gameLoop() {
    while (maxStep > step) {
        logger->log("Round " + to_string(step));
        logger->log("Applying robot upgrades");

        applyRobotRespawn();

        for (unique_ptr<GenericRobot>& robot : robotList) {
            // Skip dead robot
            if (robot->isDead())
                continue;

            logger->log(robot->getName() + "'s turn");
            printMap();
            robot->thinkAndExecute();

            this_thread::sleep_for(
                chrono::milliseconds(robotActionInterval)
            );
        }

        applyRobotUpgrades();
        applyRobotDie();

        if (robotList.size() == 1) {
            logger->log("Only one bot remains: " + robotList[0]->getName());
            gameOver();
        }
    logger->log("Steps finished");
    step++;
    }
    gameOver();
}

void Environment::gameOver()
{
    logger->log("Game Over");
    logger->log("Remaining robots: " + to_string(robotList.size()));
    if (robotList.size() == 1)
    {
        logger->log("Winner: " + robotList[0]->getName());
    }
    else if (robotList.size() == 0)
    {
        logger->log("No winner.");
    }
    else
    {
        logger->log("Multiple robots survived.");
    }
    logger->log("Game finished");
}

bool Environment::isRobotHere(Vector2D positionToCheck) const {
    return getRobotAtPosition(positionToCheck) != nullptr;
}

GenericRobot* Environment::getRobotAtPosition(Vector2D positionToCheck) const {
    for (const unique_ptr<GenericRobot> &robot : this->robotList) {
        // Skip dead robots
        if (robot->isDead())
            continue;

        if (robot->getPosition() == positionToCheck)
            // To return the raw pointer to the object, use get()
            // DO NOT RETURN THE unique_ptr ITSELF
            return robot.get();
    }

    return nullptr;
}

bool Environment::isPositionAvailable(Vector2D positionToCheck) const {
    // Position is available if no robots there and it's within bounds
    return !isRobotHere(positionToCheck) && isWithinBounds(positionToCheck);
}

bool Environment::isWithinBounds(Vector2D positionToCheck) const {
    if(positionToCheck.x >= dimension.x || positionToCheck.x < 0)
        return false;

    if(positionToCheck.y >= dimension.y || positionToCheck.y < 0)
        return false;

    return true;
}

void Environment::printMap() const
{
    // Build the map as a string and log it
    stringstream ss;
    ss << BLUE_COLOR; // Set blue color
    ss << "X ";
    for (int x = 0; x < dimension.x; ++x)
    {
        ss << "X ";
    }
    ss << "X" << RESET_COLOR << "\n"; // Reset color

    for (int y = 0; y < dimension.y; ++y)
    {
        ss << BLUE_COLOR << "X" << RESET_COLOR << " "; // Left border in blue with space
        for (int x = 0; x < dimension.x; ++x)
        {
            // Priority: fire mark > line mark > robot > empty
            if (grid[x][y] == '!')
            { 
                ss << RED_COLOR << '!' << RESET_COLOR << ' ' ; // Red fire mark
            }
            else if (grid[x][y] == '*')
            {
                ss << ORANGE_COLOR <<'*' << RESET_COLOR << ' '; // Yellow line mark
            }
            else
            {
                Vector2D pos(x, y);
                bool found = false;
                for (const unique_ptr<GenericRobot> &robot : robotList)
                {
                    if (robot->isDead())
                        continue;
                    if (robot->getPosition() == pos)
                    {
                        ss << robot->getSymbol() << " ";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    ss << ". ";
            }
        }
        ss << BLUE_COLOR << "X" << RESET_COLOR << "\n"; // Right border in blue
    }
    // Print bottom border
    ss << BLUE_COLOR;
    ss << "X ";
    for (int x = 0; x < dimension.x; ++x)
    {
        ss << "X ";
    }
    ss << "X" << RESET_COLOR << "\n";
    logger->log(ss.str());
}

// Place a fire mark at (x, y)
void Environment::placeFireMark(int x, int y)
{
    if (isWithinBounds(Vector2D(x, y)))
    {
        grid[x][y] = '!';
    }
}

// Draw a line using Bresenham's algorithm, marking '*' on empty cells
// Starts 1 block away from (x1, y1) in the direction of (x2, y2)
void Environment::drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    // Move one step from (x1, y1) towards (x2, y2)
    if (x1 != x2 || y1 != y2)
    {
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }

    while (true)
    {
        if (isWithinBounds(Vector2D(x1, y1)))
        {
            if (grid[x1][y1] == '.')
                grid[x1][y1] = '*';
        }
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// Remove all fire marks from the grid
void Environment::clearFireMarks()
{
    for (int x = 0; x < dimension.x; ++x)
    {
        for (int y = 0; y < dimension.y; ++y)
        {
            if (grid[x][y] == '!')
            {
                grid[x][y] = '.';
            }
        }
    }
}

// Remove all line marks from the grid
void Environment::clearLineMarks()
{
    for (int x = 0; x < dimension.x; ++x)
    {
        for (int y = 0; y < dimension.y; ++y)
        {
            if (grid[x][y] == '*')
            {
                grid[x][y] = '.';
            }
        }
    }
}
void Environment::notifyKill(GenericRobot *killer, GenericRobot *victim)
{
    RobotPtrIterator victimIterator = getRobotIterator(victim);
    RobotPtrIterator killerIterator = getRobotIterator(killer);

    // One robot died, so decrement
    currentRobotLength--;

    // Notify the robot on upgrading and check its upgrade-related state
    UpgradeState upgradeState = killer->chosenForUpgrade();
    if (upgradeState == AvailableForUpgrade)
        // Add to upgrade list
        // If already added before (e.g: multiple kills on 1 round),
        // the set data structure will ensure no duplication
        robotsToUpgrade.insert(killerIterator);
}

RobotPtrIterator Environment::getRobotIterator(GenericRobot* robot) {
    for (int i = 0; i < robotList.size(); i++) {
        if(robotList[i].get() == robot)
            return robotList.begin() + i;
    }

    // should never happen, will need error class for this
    return robotList.end();
}

// We cannot upgrade the right after kill
// notifyKill() is called while the robot is running thinkAndExecute()
// Upgrading the robot involves destroying the original object and replacing them with a new one
// If the robot is destroyed while thinkAndExecute() is running, it lead to segfault
// So we will only actually upgrade them at the start of each round
void Environment::applyRobotUpgrades() {
    for (const RobotPtrIterator& robotIterator : robotsToUpgrade) {
        // Get the raw robot pointer
        // For some reason you can't access it like normal pointer
        // even though at other places can
        GenericRobot* robotPtr = robotIterator->get();
        logger->log("Upgrading " + robotPtr->getName());

        // Get the pending upgrade
        vector<Upgrade> pendingUpgrades = robotPtr->getPendingUpgrades();
        GenericRobot* newRobot = nullptr;
        for (const Upgrade &upgrade : pendingUpgrades)
        {
            logger->log("Apply " + stringifyUpgrade(upgrade) + " to " + robotPtr->getName());

            switch (upgrade)
            {
            case ScoutBot:
                newRobot = new class ScoutBot(robotPtr);
                break;
            case HideBot:
                newRobot = new class HideBot(robotPtr);
                break;
            case JumpBot:
                newRobot = new class JumpBot(robotPtr);
                break;
            case LongShotBot:
                newRobot = new class LongShotBot(robotPtr);
                break;
            case SemiAutoBot:
                newRobot = new class SemiAutoBot(robotPtr);
                break;
            case ThirtyShotBot:
                newRobot = new class ThirtyShotBot(robotPtr);
                break;
            case LandmineBot:
                newRobot = new class LandmineBot(robotPtr);
                break;
            case BombBot:
                newRobot = new class BombBot(robotPtr);
                break;
            case LaserBot:
                // Replace with LaserBot later
                newRobot = new class BombBot(robotPtr);
                break;
            case TrackBot:
                newRobot = new class TrackBot(robotPtr);
            }

            logger->log("Applying " + stringifyUpgrade(upgrade) + " upgrade to " + robotPtr->getName());

            // Destroy the old GenericRobot, and switch to the new robot
            // Using iterator allow us to edit in-place, so we don't have to push it into robotList
            robotIterator->reset(newRobot);

            // Each upgrade will destroy the old robot and update it with a new pointer
            // If we keep using the old pointer it will cause havoc
            // Update it to use the new one after each upgrade
            newRobot->insertNewUpgrade(upgrade);
            robotPtr = newRobot;
        }

        robotPtr->setPosition(Vector2D(0,0));
    }

    // Clear out robotToUpgrades set
    robotsToUpgrade.clear();
}

void Environment::applyRobotDie() {
    // Notice there's no increment here
    for (auto it = robotList.begin(); it != robotList.end(); ) {
        LivingState state = it->get()->getLivingState();

        switch (state) {
            case Dead:
                // Erasing a vector's element will mess with the ordering of the element
                // erase() will return the new iterator for the next element
                // set the current iterator to the return value to avoid skipping / corruption
                it = robotList.erase(it);
                break;

            case PendingRespawn:
                // We use move() here, since we want to mark a transfer of ownership
                // from robotList to respawnQueue;
                respawnQueue.push(move(*it));
                it = robotList.erase(it);
                break;

            // Skip alive robots
            // Increment is done here
            // since the operations above will automatically set the next iterator
            case Alive:
                it++;
                continue;
        }
    }
}

// Each turn, there must be only one robot to respawn
// And it will be resetted back to GenericRobot
void Environment::applyRobotRespawn() {
    if (respawnQueue.empty()) {
        logger->log("No robots to respawn");
        return;
    }

    // Get the first element
    unique_ptr<GenericRobot>& robotUniquePtr = respawnQueue.front();
    logger->log("Respawning " + robotUniquePtr->getName());

    GenericRobot* resettedRobotPtr = new GenericRobot(*robotUniquePtr);
    robotUniquePtr.reset(resettedRobotPtr);

    // Make the robot alive again
    robotUniquePtr->notifyRespawn();

    // Re-transfer ownership back to robotList
    robotList.push_back(move(robotUniquePtr));

    // remove the first element
    respawnQueue.pop();
}

const vector<GenericRobot*> Environment::getAllAvailableRobots() const {
    vector<GenericRobot*> result;

    for (const unique_ptr<GenericRobot>& robot : robotList) {
        if (!robot->isDead())
            result.push_back(robot.get());
    }

    return result;
}


void Environment::printwelcomemessage() const
{
    stringstream ss;
    ss << "\n";
    ss << ".++######################################################################################################++.\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##   ###-   -## ########  ###      -#######  #######+ ###  #### +#######          #########- #######      ##\n";
    ss << "##    #-     .# -#        ###      ##       ##     ## ## +..##   #                    ##    ##+    ##.    ##\n";
    ss << "##    ##.+#- ## +#######  ###     -##       ##     ## ## ### #+  #######              ##    ##.    .#.    ##\n";
    ss << "##    #+## ##.# +#        ###     -##       ##     ## ##     #-  #                    ##    ##-    ##-    ##\n";
    ss << "##    -### #### ##-       ###      ###      .###  ### ##     ##  #+                   ##     ##   ##      ##\n";
    ss << "##    .#+   ##  -#######  +#######   ######-  #####   #+     ##  #######              ##      +####       ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##       #######                                                                                          ##\n";
    ss << "##      ++     ###                                                                                        ##\n";
    ss << "##     #######   -#-  #######  #######    ######  #########                                               ##\n";
    ss << "##   ##-  #   #.  #++##    ### ##    #  ##+    ##    ##                                                   ##\n";
    ss << "##     ########+  # ##.    .## ######   ##     ## .  ##-                                                  ##\n";
    ss << "##     ##    #    # ###    -## ##    ##.##     ##    ##-                                                  ##\n";
    ss << "##     ##  .###   #. ##    ##  ##   +## -##   ###    ##-                                                  ##\n";
    ss << "##      ####+ ####.   ######   ######     #####+     ###                                                  ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##     #######.-######## +##- .######    ###  ##         ###   #########.+########  ####### .###   ###    ##\n";
    ss << "##   .##           ##    +### ###+ ##    ##+  ##        #.###      +#        ##    ##    ##- ###-  ##-    ##\n";
    ss << "##     ####        ##    ####+## # ##    ###  ##        #   #     .##        ##   +#-     ## ## #+ ##-    ##\n";
    ss << "##        ####     ##    ##  #   # ##    ##+  ##      ########    .##        ##   -##     ## ## ###+#-    ##\n";
    ss << "##          ##-    ##    ##     -# ##    ##   ##      ##     ##   -##        ##    ##-   ##  ##  ####-    ##\n";
    ss << "##   -#######  .######## ##+   .##  ######    ##########     ###  +##    +########  ######  .##   ####    ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << "##                                                                                                        ##\n";
    ss << ".++######################################################################################################++.\n";
    logger->log(ss.str());
}
// void Environment::printwelcomemessage() const {
//     cout << "        __   __  ___  _______ ___      ______   ______  ___      ___  _______      ___________ ______       \n";
//     cout << "       |\"  |/  \\|  \"|/\"     |\"  |    /\" _  \"\\ /    \" \\|\"  \\    /\"  |/\"     \"|    (\"     _   \")    \" \\      \n";
//     cout << "       |'  /    \\:  (: ______)|  |   (: ( \\___)/ ____  \\\\   \\  //   (: ______)     )__/  \\\\__// ____  \\     \n";
//     cout << "       |: /'        |\\/    | |:  |    \\/ \\   /  /    ) :)\\\\  \\/.    |\\/    |          \\\\_ / /  /    ) :)    \n";
//     cout << "        \\//  /'\\    |// ___)_ \\  |___ //  \\ (: (____/ //: \\.        |// ___)_         |.  |(: (____/ //     \n";
//     cout << "        /   /  \\\\   (:      \"( \\_|:  (:   _) \\        /|.  \\    /:  (:      \"|        \\:  | \\        /      \n";
//     cout << "       |___/    \\___|\\_______)\\_______)_______)\"_____/ |___|\\__/|___|\\_______)         \\__|  \\\"_____/       \n";
//     cout << "                                                                                                            \n";
//     cout << "                              _______    ______   _______    ______ ___________                             \n";
//     cout << "                             /\"      \\  /    \" \\ |   _  \"\\  /    \" (\"     _   \")                            \n";
//     cout << "                            |:        |// ____  \\(. |_)  :)// ____  )__/  \\\\__/                             \n";
//     cout << "                            |_____/   )  /    ) :):     \\//  /    ) :) \\\\_ /                                \n";
//     cout << "                             //      (: (____/ //(|  _  \\(: (____/ //  |.  |                                \n";
//     cout << "                            |:  __   \\\\        / |: |_)  :)        /   \\:  |                                \n";
//     cout << "                            |__|  \\___)\\\"_____/  (_______/ \\\"_____/     \\__|                                \n";
//     cout << "                                                                                                            \n";
//     cout << "      ________ __    ___      ___ ____  ____ ___           __ ___________ __     ______   _____  ___        \n";
//     cout << "     /\"       )\" \\  |\"  \\    /\"  (\"  _||_ \" |\"  |         /\"\"(\"     _   \")\" \\   /    \" \\ (\"   \\|\"  \\       \n";
//     cout << "    (:   \\___/||  |  \\   \\  //   |   (  ) : ||  |        /    )__/  \\\\__/||  | // ____  \\|.\\\\   \\    |      \n";
//     cout << "     \\___  \\  |:  |  /\\\\  \\/.    (:  |  | . ):  |       /' /\\  \\ \\\\_ /   |:  |/  /    ) :): \\.   \\\\  |      \n";
//     cout << "      __/  \\\\ |.  | |: \\.        |\\\\ \\__/ // \\  |___   //  __'  \\|.  |   |.  (: (____/ //|.  \\    \\. |      \n";
//     cout << "     /\" \\   :)/\\  |\\|.  \\    /:  |/\\\\ __ //\\( \\_|:  \\ /   /  \\\\  \\:  |   /\\  |\\        / |    \\    \\ |      \n";
//     cout << "    (_______/(__\\_|_)___|\\__/|___(__________)\\_______|___/    \\___)__|  (__\\_|_)\"_____/   \\___|\\____\\)      \n";
//     cout << endl
//             << endl;
// }
