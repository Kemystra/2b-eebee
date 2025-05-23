#include "ParameterFileReader.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

bool ParameterFileReader::readFile(const string& filename, bool requireAllParams) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw ParseError("Cannot open file: " + filename);
    }

    string line;
    while (getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#' || (line.size() > 1 && line[0] == '/' && line[1] == '/')) {
            continue;
        }
        try {
            parseLine(line);
        } catch (const exception& e) {
            throw ParseError("Error parsing line: " + string(e.what()) + "\nLine: " + line);
        }
    }

    validateParameters(requireAllParams);
    return true;
}

void ParameterFileReader::parseLine(const string& line) {
    string trimmedLine = trim(line);
    string lowerLine = toLower(trimmedLine);

    if (lowerLine.rfind("m by n", 0) == 0) { // starts with "m by n"
        size_t colonPos = trimmedLine.find(':');
        if (colonPos == string::npos) {
            throw runtime_error("Expected ':' after 'M by N'");
        }
        string numbers = trimmedLine.substr(colonPos + 1);
        istringstream iss(numbers);
        if (!(iss >> m >> n)) {
            throw runtime_error("Expected two integers after 'M by N:'");
        }
        if (m <= 0 || n <= 0) {
            throw runtime_error("Field dimensions must be positive integers");
        }
    }

    else if (lowerLine.rfind("steps:", 0) == 0) {
        istringstream iss(trimmedLine.substr(6)); // Skip "steps:"
        if (!(iss >> steps) || steps <= 0) {
            throw runtime_error("Steps must be a positive integer");
        }
    }

    else if (lowerLine.rfind("robots:", 0) == 0) {
        istringstream iss(trimmedLine.substr(7)); // Skip "robots:"
        if (!(iss >> robotCount) || robotCount <= 0) {
            throw runtime_error("Robot count must be a positive integer");
        }
    }

    else {
        istringstream iss(trimmedLine);
        RobotInfo robot;
        if (!(iss >> robot.type >> robot.name)) {
            throw runtime_error("Missing robot type or name");
        }

        string posX, posY;
        if (!(iss >> posX >> posY)) {
            throw runtime_error("Missing robot position");
        }

        if (isRandomPos(posX) || isRandomPos(posY)) {
            robot.x = -1;
            robot.y = -1;
            robot.isRandomPosition = true;
        } else {
            try {
                robot.x = stoi(posX);
                robot.y = stoi(posY);
                if (robot.x < 0 || robot.y < 0) {
                    throw runtime_error("Robot position cannot be negative");
                }
            } catch (...) {
                throw runtime_error("Invalid position format");
            }
        }

        robots.push_back(robot);
    }
}



void ParameterFileReader::validateParameters(bool requireAllParams) {
    if (requireAllParams) {
        if (m == -1 || n == -1) {
            throw ParseError("Missing field dimensions (M by N)");
        }
        if (steps == -1) {
            throw ParseError("Missing number of steps");
        }
    }

    if (robotCount != static_cast<int>(robots.size())) {
        throw ParseError("Robot count does not match declared number");
    }
}

string ParameterFileReader::toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
              [](unsigned char c) { return tolower(c); });
    return lowerStr;
}

string ParameterFileReader::trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

bool ParameterFileReader::isRandomPos(const string& s) {
    string lower = toLower(s);
    return lower == "random" || lower == "any";
}


#include "ParameterFileReader.h"
#include <iostream>

using namespace std;

int main() {
    ParameterFileReader reader;
        reader.readFile("parameter.txt", true);
        cout << "Field size: " << reader.getM() << " by " << reader.getN() << endl;
        cout << "Steps: " << reader.getSteps() << endl;
        cout << "Number of robots: " << reader.getRobotCount() << endl;

        for (const auto& robot : reader.getRobots()) {
            cout << "Robot type: " << robot.type
                 << ", name: " << robot.name
                 << ", position: (" << robot.x << ", " << robot.y << ")";
            if (robot.isRandomPosition) {
                cout << " [random]";
            }
            cout << endl;
        }

    return 0;
}
