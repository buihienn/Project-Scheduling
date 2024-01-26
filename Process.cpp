#include "Process.h"

Process::Process (int name, int arrTime, int burstTime, int priorityLevel, int waitingTime, int turnaroundTime){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = priorityLevel;
    this->waitingTime = waitingTime;
    this->turnaroundTime = turnaroundTime; 
}

Process::Process (int name, int arrTime, int burstTime){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = 0;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
    
}

Process::Process (int name, int arrTime, int burstTime, int priorityLevel){
    this->name = name;
    this->arrTime = arrTime;
    this->burstTime = burstTime;
    this->priorityLevel = priorityLevel;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
}

//Set
void Process:: setTurnAroundTime(int value){
    turnaroundTime = value;
}

void Process:: setWaitingTime(int value){
    waitingTime = value;
}



// Get
int Process::getName(){
    return name;
}
int Process::getArrTime(){
    return arrTime;
}
int Process::getBurstTime(){
    return burstTime;
}
int Process::getPriorityLevel(){
    return priorityLevel;
}
int Process::getWaitingTime(){
    return waitingTime;
}
int Process::getTurnaroundTime(){
    return turnaroundTime;
}

