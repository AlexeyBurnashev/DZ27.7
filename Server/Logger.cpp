#include "Logger.h"

void Logger::writeLog(const string& message) {
    unique_lock<shared_mutex> lock(mutex);

    if (!file.is_open()) {
        cerr << "Failed to open log file." << "\n";
        return;
    }

    file << message << "\n";

    file.close();
}

string Logger::readLog() const {
    shared_lock<shared_mutex> lock(mutex);

    ifstream logFile("log.txt");

    if (logFile.fail()) {
        cerr << "Failed to open log file." << "\n";
        return "";
    }

    if (logFile.is_open()) {
        string line;
        string lastLine;

        while (getline(logFile, line)) {
            lastLine = line;
        }

        logFile.close();

        return lastLine;
    }
    else {
        return "";
    }
}