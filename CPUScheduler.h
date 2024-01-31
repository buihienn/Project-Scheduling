#pragma once
#include "Process.h"
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

    virtual void excuted() = 0;
    void exportData();
    void calTurnaroundTime();
    void calWaitingTime();
};