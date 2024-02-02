#pragma once
#include "CPUScheduler.h"
#include <vector>
#include <algorithm>

class RoundRobin : public Scheduler {
public:
    int quantumTime;

    RoundRobin (){}
    RoundRobin (std::vector <Process> &processes, int quantumTime);
    void executed() override;

    void checkAndUpdateQuantumTime(int &tempQuantum);
};

