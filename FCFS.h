#pragma once
#include "Process.h"
#include <algorithm>
#include <iostream>
#include "CPUScheduler.h"
bool checkOutRR(std::vector <Process>& processes);
void checkToPushRR(std::vector <Process*> &address, std::vector <Process*> &destination);
void FCFS(std::vector <Process> &processes);
