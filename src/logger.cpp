#include "logger.h"

Logger::Logger() {
    logFile.open("log.txt", ios::app);
}

void Logger::outputToConsole(const string& message) {
    cout << message << endl;
}

void Logger::outputToFile(const string& message, const string& filename) {
    if (logFile.is_open()) {
        logFile << message << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}        
void Logger::log(const string& message) {
    outputToConsole(message);
    outputToFile(message, "log.txt");
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}


