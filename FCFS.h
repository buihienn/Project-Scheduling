#pragma once
#include <algorithm>
#include "CPUScheduler.h"

class FCFS :public Scheduler {
public:
    FCFS() {}
    FCFS(std::vector <Process> &processes);
    void executed() override;
};

