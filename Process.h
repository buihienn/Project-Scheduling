#pragma once
#include <string>

class Process {
private:
    int name;
    int arrTime;
    int burstTime;
    int priorityLevel;
    int waitingTime;
    int turnaroundTime;
public:
    Process (int name, int arrTime, int burstTime, int priorityLevel, int waitingTime, int turnaroundTime);
    Process (int name, int arrTime, int burstTime);
    Process (int name, int arrTime, int burstTime, int priorityLevel);

    void setTurnAroundTime(int value);
    void setWaitingTime(int value);

    int getName();
    int getArrTime();
    int getBurstTime();
    int getPriorityLevel();
    int getWaitingTime();
    int getTurnaroundTime();
};