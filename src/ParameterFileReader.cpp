#include "ParameterFileReader.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

bool ParameterFileReader::readFile(const string& filename, bool requireAllParams) { // Open the file
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

enum class LineType { // Enum to categorize line types
    M_BY_N,
    STEPS,
    ROBOTS,
    ROBOT_INFO,
    SEED,
    UNKNOWN
};

const int MISSING_INT = -1;

LineType getLineType(const string& lowerLine) { // Determine the type of line based on its content
    if (lowerLine.rfind("m by n", 0) == 0) return LineType::M_BY_N;
    if (lowerLine.rfind("steps:", 0) == 0) return LineType::STEPS;
    if (lowerLine.rfind("robots:", 0) == 0) return LineType::ROBOTS;
    if (lowerLine.rfind("seed:", 0) == 0) return LineType::SEED;
    return LineType::ROBOT_INFO; // Default case
}

// LineType 
void ParameterFileReader::parseLine(const string& line){ // Parse a single line of the parameter file
    string trimmedLine = trim(line);
    string lowerLine = toLower(trimmedLine);
    
    switch (getLineType(lowerLine)) {
        case LineType::M_BY_N: {
            size_t colonPos = trimmedLine.find(':');
            if (colonPos == string::npos) {
                throw runtime_error("Expected ':' after 'M by N'");
            }
            string numbers = trimmedLine.substr(colonPos + 1);
            istringstream iss(numbers);
            if (!(iss >> m >> n)) {
                throw runtime_error("Expected two integers after 'M by N:'");
            }
            break;
        }

        case LineType::STEPS: {
            istringstream iss(trimmedLine.substr(6)); // Skip "steps:"
            if (!(iss >> steps)) {
                throw runtime_error("Expected an integer after 'steps:'");
            }
            break;
        }

        case LineType::ROBOTS: {
            istringstream iss(trimmedLine.substr(7)); // Skip "robots:"
            if (!(iss >> robotCount)) {
                throw runtime_error("Expected an integer after 'robots:'");
            }
            break;
        }

        case LineType::ROBOT_INFO: {
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
                robot.x = MISSING_INT;
                robot.y = MISSING_INT;
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
            break;
        }

        default:
            throw runtime_error("Unknown line type");
    }
}



void ParameterFileReader::validateParameters(bool requireAllParams) { // Validate the parameters read from the file
    // Stop if validation is not needed
    if (!requireAllParams)
        return;

    if (m <= 0 || n <= 0) {
        throw runtime_error("Field dimensions must be positive integers");
    }

    if (steps <= 0)
        throw runtime_error("Step must be a positive integer");

    if (robotCount <= 0)
        throw runtime_error("Robot count must be a positive integer");

    if (steps == MISSING_INT) {
        throw ParseError("Missing number of steps");
    }

    if (robotCount != static_cast<int>(robots.size())) {
        throw ParseError("Robot count does not match declared number");
    }
}

string ParameterFileReader::toLower(const string& str) { // Convert a string to lowercase
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
              [](unsigned char c) { return tolower(c); });
    return lowerStr;
}

string ParameterFileReader::trim(const string& str) { // Trim whitespace from both ends of a string
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

bool ParameterFileReader::isRandomPos(const string& s) { // Check if a string represents a random position
    string lower = toLower(s);
    return lower == "random" || lower == "any";
}


