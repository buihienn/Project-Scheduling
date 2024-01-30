#pragma once
#include <string>
#include <vector>

struct Process {
    int name;
    int arrTime;
    std::vector <int> burstTime; // Even = CPU - Odd = Resources
    int waitingTime;
    int turnaroundTime;
    int status; // 0 = Done, Even =  CPU, Odd = in  Resources.

    Process (int name, int arrTime, std::vector <int> burstTime,  int waitingTime, int turnaroundTime,int status);
    Process (int name, int arrTime, std::vector <int> burstTime);
};

