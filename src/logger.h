#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
class Logger{
    private:
        ofstream logFile;
        stringstream buffer;
    public:
        Logger();
        ~Logger();
        void log(const string& message);
        void outputToConsole(const string& message) ;
        void outputToFile(const string& message, const string& filename);
        void error(const string& message);
        void setBufferColor(const char* color);
        void resetBufferColor();
        void bufferedLog(const string& message);
        void flushBufferedLog();
};


    #endif // LOGGER_H
