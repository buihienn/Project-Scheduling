#pragma once
#include "Process.h"
#include <algorithm>
#include <iostream>
#include "CPUScheduler.h"

class FCFS :public Scheduler {
public:
    FCFS() {}
    FCFS(std::vector <Process> &processes);
    void excuted() override;
};

bool checkOut(std::vector <Process>& processes);
void checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination);

