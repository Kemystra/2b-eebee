#ifndef PARAMETERFILEREADER_H
#define PARAMETERFILEREADER_H

#include <cstdint>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct RobotInfo{ // Structure to hold robot information
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

    ParameterFileReader() = default;

    bool readFile(const string&filename, bool requireAllParams = true); // Read and parse the parameter file

    int getM() const {return m;}
    int getN() const {return n;}
    int getSteps() const {return steps;}
    int getRobotCount() const { return robotCount;}
    const vector<RobotInfo>& getRobots() const {return robots;}

    private:
    // Size of the battlefield
    int m = -1;
    int n = -1;

    // Number of turns
    int steps = -1;

    // Seed to be passed into the RNG
    // If they use the same seed, the same sequence of random numbers will be used
    uint_fast64_t seed;

    // Number of robots
    int robotCount = 0;
    vector<RobotInfo> robots;
    
    void parseLine(const string&line);
    void validateParameters(bool requuireAllParams);
    static string trim(const string&str);
    static string toLower(const string&str);
    static bool isRandomPos(const string&s);

};

#endif
