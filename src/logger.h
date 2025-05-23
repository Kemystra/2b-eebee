#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Logger{
    private:
       ofstream logFile;
    public:
        Logger();
        ~Logger();
        void log(const string& message);
        void outputToConsole(const string& message) ;
        void outputToFile(const string& message, const string& filename);

};


#endif // LOGGER_H