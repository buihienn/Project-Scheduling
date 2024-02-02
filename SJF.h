#pragma once

#include "CPUScheduler.h"
#include <algorithm>


class SJF : public Scheduler {
public:
    SJF() {}
    SJF(std::vector <Process> &processes);
    void executed() override;
};