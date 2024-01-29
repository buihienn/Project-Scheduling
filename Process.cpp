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

//Set
// void Process:: setTurnAroundTime(int value){
//     turnaroundTime = value;
// }

// void Process:: setWaitingTime(int value){
//     waitingTime = value;
// }

// void Process::setStatus(int value){
//     status = value;
// }
// void Process::BurstTimeSub(int index){
//     burstTime[index]--;
// }

// // Get
// int Process::getName(){
//     return name;
// }
// int Process::getArrTime(){
//     return arrTime;
// }
// int Process::getBurstTime(int index){
//     return burstTime[index];
// }
// int Process::getPriorityLevel(){
//     return priorityLevel;
// }
// int Process::getWaitingTime(){
//     return waitingTime;
// }
// int Process::getTurnaroundTime(){
//     return turnaroundTime;
// }
// int Process::getStatus(){
//     return status;
// }
// int Process::getNumBurstTime(){
//     return burstTime.size();
// }

