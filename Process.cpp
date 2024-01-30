#include "Process.h"

Process::Process (int name, int arrTime, std::vector<int> burstTime, int priorityLevel, int waitingTime, int turnaroundTime, int status){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = priorityLevel;
    this->waitingTime = waitingTime;
    this->turnaroundTime = turnaroundTime; 
    this->status = status;
}

Process::Process (int name, int arrTime, std::vector<int> burstTime){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = 0;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
    this->status = 0;
}

Process::Process (int name, int arrTime, std::vector<int> burstTime, int priorityLevel){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = priorityLevel;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
    this->status = 0;
}
