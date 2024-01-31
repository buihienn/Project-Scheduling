#pragma once
#include "CPUScheduler.h"
#include <vector>
#include <algorithm>

bool checkOut(std::vector <Process>& processes);
void checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination);
void RR(std::vector <Process> &processes, int quantumTime);
