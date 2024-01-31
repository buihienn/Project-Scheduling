#pragma once
#include "CPUScheduler.h"
#include <vector>
#include <algorithm>

class RoundRobin : public Scheduler {
public:
    int quantumTime;

    RoundRobin (){}
    RoundRobin (std::vector <Process> &processes, int quantumTime);
    void excuted() override;
};

bool checkOutRR(std::vector <Process>& processes);
void checkToPushRR(std::vector <Process*> &address, std::vector <Process*> &destination);
