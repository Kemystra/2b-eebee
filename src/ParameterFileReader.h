#ifndef PARAMETERFILEREADER_H
#define PARAMETERFILEREADER_H

#include <cstdint>
#include <string>
#include <vector>
#include <stdexcept>

#include "genericRobot.h"
#include "utils/types.h"

using namespace std;

struct RawRobotInfo{ // Structure to hold robot information
    string type;
    string name;
    int x;
    int y;
    bool isRandomPosition;
};

class ParameterFileReader{ // Class to read and parse a parameter file for a robot simulation
    public:
    class ParseError: public runtime_error{
        using runtime_error::runtime_error;
    };

    ParameterFileReader();

    bool readFile(const string&filename, bool requireAllParams = true); // Read and parse the parameter file

    int getM() const {return m;}
    int getN() const {return n;}
    int getSteps() const {return steps;}
    int getRobotCount() const { return robotCount;}
    const vector<RobotParameter>& getRobots() const {return finalRobotInfo;}

    private:
    // Size of the battlefield
    int m = -1;
    int n = -1;

    // Number of turns
    int steps = -1;

    // Seed to be passed into the RNG
    // If they use the same seed, the same sequence of random numbers will be used
    RngSeed seed;

    // Number of robots
    int robotCount = 0;
    vector<RawRobotInfo> rawRobotInfo;
    vector<RobotParameter> finalRobotInfo;
    
    void parseLine(const string&line);
    int parseInt(istringstream& stream, const string& errorMsg);
    int parseIntOrRandom(istringstream& stream, const string& errorMsg);

    void finalizeParameters(bool requuireAllParams);
    static string trim(const string&str);
    static string toLower(const string&str);
    static bool isRandomPos(const string&s);
};

#endif
