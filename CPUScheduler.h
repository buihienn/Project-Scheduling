#pragma once
#include "Process.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class Scheduler {
protected:
    std::vector <Process> processes;
    std::vector <Process*> readyQueue;
    std::vector <Process*> listR;
    std::vector <int> CPU;
    std::vector <int> R;
public:
    Scheduler(){}

    virtual void executed() = 0;
    void exportData(std::string filename);
    void calTurnaroundTime();
    void calWaitingTime();
    bool checkOut(std::vector <Process>& processes);
    void checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination);
};