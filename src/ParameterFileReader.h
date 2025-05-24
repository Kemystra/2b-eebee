#ifndef PARAMETERFILEREADER_H
#define PARAMETERFILEREADER_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct RobotInfo{
    string type;
    string name;
    int x;
    int y;
    bool isRandomPosition;
};

class ParameterFileReader{
    public:
    class ParseError: public runtime_error{
        using runtime_error::runtime_error;
    };

    ParameterFileReader() = default;

    bool readFile(const string&filename, bool requireAllParams = true);

    int getM() const {return m;}
    int getN() const {return n;}
    int getSteps() const {return steps;}
    int getRobotCount() const { return robotCount;}
    const vector<RobotInfo>& getRobots() const {return robots;}

    private:
    int m = -1;
    int n = -1;
    int steps = -1;
    int robotCount = 0;
    vector<RobotInfo> robots;
    
    void parseLine(const string&line);
    void validateParameters(bool requuireAllParams);
    static string trim(const string&str);
    static string toLower(const string&str);
    static bool isRandomPos(const string&s);

};

#endif