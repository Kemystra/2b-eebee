#include "environment.h"
#include "abstractRobot/robot.h"
#include "genericRobot.h"
#include "upgrades/upgrades.h"
#include "vector2d.h"

#include <memory>
#include <random>
#include <algorithm>

// Needed for sleep function
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

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

    // Temporary RNG to seed the robots RNG
    // We are using another RNG instead of just passing the same seed
    // so that all the robots won't do the same thing at the same time
    mt19937_64 rng(69420);

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
    GenericRobot* robot = new GenericRobot(param, this, rng(), logger);
    this->robotList.push_back(unique_ptr<GenericRobot>(robot));
    }
}

void Environment::gameLoop() {
    while (maxStep > step && robotList.size() > 1) {
        // Make a copy of pointers to robots to avoid iterator invalidation
        vector<GenericRobot*> robotsToAct;
        for (auto& robotPtr : robotList) {
            robotsToAct.push_back(robotPtr.get());
        }

        for (GenericRobot* robot : robotsToAct) {

    while (maxStep > step) {
        logger->log("Round " + to_string(step));
        logger->log("Applying robot upgrades");
        applyRobotUpgrades();

        for (unique_ptr<GenericRobot> &robot : this->robotList) {
            logger->log(robot->getName() + "'s turn");
            printMap();
            // Only act if the robot is still in the list (not killed this turn)
            if (find_if(robotList.begin(), robotList.end(),
                [robot](const unique_ptr<GenericRobot>& ptr) { return ptr.get() == robot; }) != robotList.end()) {
                robot->thinkAndExecute();
                this_thread::sleep_for(chrono::milliseconds(robotActionInterval));
            }
        }


        if (robotList.size() == 1) {
            logger->log("Only one bot remains: " + robotList[0]->getName());
            gameOver();

        }

        step++;
        this_thread::sleep_for(chrono::milliseconds(stepInterval));
    }

}

void Environment::gameOver() {
    cout << "Game Over" << endl;
    cout << "Remaining robots: " << robotList.size() << endl;
    if (robotList.size() == 1) {
        cout << "Winner: " << robotList[0]->getName() << endl;
    } else if (robotList.size() == 0) {
        cout << "No winner." << endl;
    } else {
        cout << "Multiple robots survived." << endl;
    }

    logger->log("Steps finished");
    logger->log("Game finished");
}


}

bool Environment::isRobotHere(Vector2D positionToCheck) const {
    for (const unique_ptr<GenericRobot> &robot : this->robotList) {
        if (robot->getPosition() == positionToCheck)
            return true;
    }

    return false;
}

GenericRobot* Environment::getRobotAtPosition(Vector2D positionToCheck) {
    for (unique_ptr<GenericRobot> &robot : this->robotList) {
        if (robot->getPosition() == positionToCheck)

            // To return the raw pointer to the object, use get()
            // DO NOT RETURN THE unique_ptr ITSELF
            return robot.get();
    }

    return nullptr;
}

bool Environment::isPositionAvailable(Vector2D positionToCheck) const {
    // Position is available if no robots there and it's within bounds
    return !isRobotHere(positionToCheck) || isWithinBounds(positionToCheck);
}

bool Environment::isWithinBounds(Vector2D positionToCheck) const {
    if(positionToCheck.x > dimension.x || positionToCheck.x < 0)
        return false;

    if(positionToCheck.y > dimension.y || positionToCheck.y < 0)
        return false;

    return true;
}


void Environment::printMap() const {
    // Print top border
    cout << "\033[34m"; // Set blue color
    cout << "X ";
    for (int x = 0; x < dimension.x; ++x) {
        cout << "X ";
    }
    cout << "X\033[0m\n"; // Reset color

    for (int y = 0; y < dimension.y; ++y) {
        cout << "\033[34mX\033[0m "; // Left border in blue with space
        for (int x = 0; x < dimension.x; ++x) {
            // Priority: fire mark > line mark > robot > empty
            if (grid[x][y] == '!') {
                cout << "\033[31m! \033[0m"; // Red fire mark
            } else if (grid[x][y] == '*') {
                cout << "\033[33m* \033[0m"; // Yellow line mark
            } else {
                Vector2D pos(x, y);
                bool found = false;
                for (const unique_ptr<GenericRobot> &robot : robotList) {
                    if (robot->getPosition() == pos) {
                        cout << robot->getSymbol() << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << ". ";
            }
        }
        cout << "\033[34mX\033[0m\n"; // Right border in blue
    }
    // Print bottom border
    cout << "\033[34m";
    cout << "X ";
    for (int x = 0; x < dimension.x; ++x) {
        cout << "X ";
    }
    cout << "X\033[0m\n";
}

// Place a fire mark at (x, y)
void Environment::placeFireMark(int x, int y) {
    if (x >= 0 && x < dimension.x && y >= 0 && y < dimension.y) {
        grid[x][y] = '!';
    }
}

 // Draw a line using Bresenham's algorithm, marking '*' on empty cells
// Starts 1 block away from (x1, y1) in the direction of (x2, y2)
void Environment::drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    // Move one step from (x1, y1) towards (x2, y2)
    if (x1 != x2 || y1 != y2) {
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }

    while (true) {
        if (x1 >= 0 && x1 < dimension.x && y1 >= 0 && y1 < dimension.y) {
            if (grid[x1][y1] == '.') grid[x1][y1] = '*';
        }
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Remove all fire marks from the grid
void Environment::clearFireMarks() {
    for (int x = 0; x < dimension.x; ++x) {
        for (int y = 0; y < dimension.y; ++y) {
            if (grid[x][y] == '!') {
                grid[x][y] = '.';
            }
        }
    }
}

// Remove all line marks from the grid
void Environment::clearLineMarks() {
    for (int x = 0; x < dimension.x; ++x) {
        for (int y = 0; y < dimension.y; ++y) {
            if (grid[x][y] == '*') {
                grid[x][y] = '.';
            }
        }
    }
}
void Environment::notifyKill(GenericRobot* killer, GenericRobot* victim, DeadState deadState) {
    RobotPtrIterator victimIterator = getRobotIterator(victim);
    RobotPtrIterator killerIterator = getRobotIterator(killer);

    // Notify the robot on upgrading and check its upgrade-related state
    UpgradeState upgradeState = killer->chosenForUpgrade();
    if (upgradeState == AvailableForUpgrade)
        // Add to upgrade list
        // If already added before (e.g: multiple kills on 1 round),
        // the set data structure will ensure no duplication
        robotsToUpgrade.insert(killerIterator);

    // If respawn move to respawn queue, else just delete urself lol
    switch (deadState) {
        case DeadState::Respawn:
            respawnQueue.push(move(*victimIterator));
            logger->log("Put " + victimIterator->get()->getName() + " into the respawn queue");
        break;

        case DeadState::Dead:
            robotsToDie.insert(victimIterator);
        break;
    }
}

RobotPtrIterator Environment::getRobotIterator(GenericRobot* robot) {
    for (int i = 0; i < robotList.size(); i++) {
        if(robotList[i].get() == robot)
            return robotList.begin() + i;
    }

    // should never happen, will need error class for this
    return robotList.end();
}


vector<unique_ptr<GenericRobot>>& Environment::getAllRobots() {
    return this->robotList;
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

        for (const Upgrade& upgrade : pendingUpgrades) {
            logger->log("Apply " + stringifyUpgrade(upgrade) + " to " + robotPtr->getName());
            // Will apply upgrades later
            GenericRobot* newRobot = new GenericRobot(*robotPtr);

            // Destroy the old GenericRobot, and switch to the new robot
            // Using iterator allow us to edit in-place, so we don't have to push it into robotList
            robotIterator->reset(newRobot);
        }
    }
}

void Environment::applyRobotRespawn() {
}

void Environment::applyRobotDie() {
}

vector<unique_ptr<GenericRobot>>& Environment::getAllRobots() {
    return this->robotList;
}

vector<unique_ptr<GenericRobot>>& Environment::getAllRobots() {
    return this->robotList;
}


void Environment::printwelcomemessage() const {
    cout << ".++######################################################################################################\n";                              
    cout << "##                                                                                                        ##\n";                 
    cout << "##                                                                                                        ##\n";                 
    cout << "##                                                                                                        ##\n";                 
    cout << "##   ###-   -## ########  ###      -#######  #######+ ###  #### +#######          #########- #######      ##\n";                 
    cout << "##    #-     .# -#        ###      ##       ##     ## ## +..##   #                    ##    ##+    ##.    ##\n";                 
    cout << "##    ##.+#- ## +#######  ###     -##       ##     ## ## ### #+  #######              ##    ##.    .#.    ##\n";               
    cout << "##    #+## ##.# +#        ###     -##       ##     ## ##     #-  #                    ##    ##-    ##-    ##\n";               
    cout << "##    -### #### ##-       ###      ###      .###  ### ##     ##  #+                   ##     ##   ##      ##\n";                  
    cout << "##    .#+   ##  -#######  +#######   ######-  #####   #+     ##  #######              ##      +####       ##\n";                 
    cout << "##                                                                                                        ##\n";                                
    cout << "##                                                                                                        ##\n";               
    cout << "##                                                                                                        ##\n";                 
    cout << "##       #######                                                                                          ##\n";               
    cout << "##      ++     ###                                                                                        ##\n";                 
    cout << "##     #######   -#-  #######  #######    ######  #########                                               ##\n";               
    cout << "##   ##-  #   #.  #++##    ### ##    #  ##+    ##    ##                                                   ##\n";                 
    cout << "##     ########+  # ##.    .## ######   ##     ## .  ##-                                                  ##\n";                  
    cout << "##     ##    #    # ###    -## ##    ##.##     ##    ##-                                                  ##\n";               
    cout << "##     ##  .###   #. ##    ##  ##   +## -##   ###    ##-                                                  ##\n";               
    cout << "##      ####+ ####.   ######   ######     #####+     ###                                                  ##\n";               
    cout << "##                                                                                                        ##\n";   
    cout << "##                                                                                                        ##\n";
    cout << "##                                                                                                        ##\n";
    cout << "##     #######.-######## +##- .######    ###  ##         ###   #########.+########  ####### .###   ###    ##\n";
    cout << "##   .##           ##    +### ###+ ##    ##+  ##        #.###      +#        ##    ##    ##- ###-  ##-    ##\n";
    cout << "##     ####        ##    ####+## # ##    ###  ##        #   #     .##        ##   +#-     ## ## #+ ##-    ##\n";                  
    cout << "##        ####     ##    ##  #   # ##    ##+  ##      ########    .##        ##   -##     ## ## ###+#-    ##\n";
    cout << "##          ##-    ##    ##     -# ##    ##   ##      ##     ##   -##        ##    ##-   ##  ##  ####-    ##\n";   
    cout << "##   -#######  .######## ##+   .##  ######    ##########     ###  +##    +########  ######  .##   ####    ##\n";
    cout << "##                                                                                                        ##\n";                 
    cout << "##                                                                                                        ##\n";
    cout << "##                                                                                                        ##\n";
    cout << ".++#########################################################################################################\n";  
    cout << endl
            << endl;
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


