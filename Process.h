#pragma once
#include <string>
#include <vector>

struct Process {
    int name;
    int arrTime;
    std::vector <int> burstTime; // Even = CPU - Odd = Resources
    int priorityLevel;
    int waitingTime;
    int turnaroundTime;
    int status; // 0 = Done, Even =  CPU, Odd = in  Resources.

    Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel, int waitingTime, int turnaroundTime,int status);
    Process (int name, int arrTime, std::vector <int> burstTime);
    Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel);
};

