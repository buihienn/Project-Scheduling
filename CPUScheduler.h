#pragma once
#include "Process.h"
#include <iostream>


void exportData(std::vector <int> CPU, std::vector <int> R, std::vector <Process>& processes);
void calTurnaroundTime(std::vector<Process> &processes, std::vector <int> &CPU, std::vector<int> &R);
void calWaitingTime(std::vector<Process> &processes, std::vector <int> &CPU, std::vector<int> &R);