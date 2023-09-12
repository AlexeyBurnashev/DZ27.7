#pragma once
#include <iostream>
#include <fstream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>

using namespace std;

class Logger {
private:
    ofstream file;
    mutable shared_mutex mutex;

public:
    Logger(const string& filename) : file(filename, ios_base::app), mutex()
    {
        if (!file.is_open()) {
            file.open(filename);
        }
    }

    ~Logger() {
        if (file.is_open()) {
            file.close();
        }
    }

    void writeLog(const string& message);

    string readLog() const;
};