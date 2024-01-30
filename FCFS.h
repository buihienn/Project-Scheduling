#pragma once
#include "Process.h"
#include <algorithm>
#include <iostream>
#include "CPUScheduler.h"
bool checkOut(std::vector <Process>& processes);
void checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination);
void FCFS(std::vector <Process> &processes);
