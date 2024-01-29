#pragma once
#include "Process.h"
#include <algorithm>
#include <iostream>


void FCFS(std::vector <Process> &processes,  std::vector <int> &timeLine, int count);
void print(std::vector <int> t);
bool checkOut(std::vector <Process>& processes);
void Do(std::vector <Process> &processes);

void Test(std::vector <Process> &processes);