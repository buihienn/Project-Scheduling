#pragma once
#include <string>
#include <vector>

struct Process {
    int name;
    int arrTime;
    std::vector <int> burstTime; // Even = CPU - Odd = I/O
    int priorityLevel;
    int waitingTime;
    int turnaroundTime;
    int status; // 0 = Done, Even =  CPU, Odd = in  Register.

    Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel, int waitingTime, int turnaroundTime,int status);
    Process (int name, int arrTime, std::vector <int> burstTime);
    Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel);
};

// class Process {
// private:
//     int name;
//     int arrTime;
//     std::vector <int> burstTime; // Even = CPU - Odd = I/O
//     int priorityLevel;
//     int waitingTime;
//     int turnaroundTime;
//     int status; // 0 = Done, 1 = in CPU, 2 = in  Register.
// public:
//     Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel, int waitingTime, int turnaroundTime,int status);
//     Process (int name, int arrTime, std::vector <int> burstTime);
//     Process (int name, int arrTime, std::vector <int> burstTime, int priorityLevel);

//     void setTurnAroundTime(int value);
//     void setWaitingTime(int value);
//     void BurstTimeSub(int index);
//     void setStatus(int value);

//     int getName();
//     int getArrTime();
//     int getBurstTime(int index);
//     int getPriorityLevel();
//     int getWaitingTime();
//     int getTurnaroundTime();
//     int getStatus();
//     int getNumBurstTime();
// };