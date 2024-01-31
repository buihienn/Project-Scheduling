#pragma once

#include "CPUScheduler.h"
#include <algorithm>

class SRTN : public Scheduler {
public:
    SRTN() {}
    SRTN(std::vector <Process> &processes);
    void excuted() override;
};