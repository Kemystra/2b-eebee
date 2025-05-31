#include "logger.h"

Logger::Logger() {
    logFile.open("log.txt");
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

void Logger::error(const string& message){
    string errorMessage = "Error: " + message;
    outputToConsole(errorMessage);
    outputToFile(errorMessage,"log.txt");
}

void Logger::setBufferColor(const char* color) {
    buffer << color;
}
void Logger::resetBufferColor() {
    buffer << "\033[0m"; // Reset color to default
}

void Logger::bufferedLog(const string& message) {
    buffer << message;
};

void Logger::flushBufferedLog() {
    if (buffer.str().empty()) return; // No buffered log to flush
    outputToConsole(buffer.str());
    outputToFile(buffer.str(), "log.txt");
    buffer.str(""); // Clear the buffer after flushing
}
