#pragma once
#include "Process.h"
#include <algorithm>
#include "CPUScheduler.h"

class FCFS :public Scheduler {
public:
    FCFS() {}
    FCFS(std::vector <Process> &processes);
    void excuted() override;
};

