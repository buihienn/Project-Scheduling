#include "RoundRobin.h"

RoundRobin::RoundRobin (std::vector <Process> &processes, int quantumTime){
    this->processes = processes;
    this->quantumTime = quantumTime;
}

bool checkOutRR(std::vector <Process>& processes){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            return false;
        }
    }
    return true;
}

void checkToPushRR(std::vector <Process*> &address, std::vector <Process*> &destination){
    if (!address.empty()){
        destination.push_back(address[0]);
        address.pop_back();
    }
}

void RoundRobin::excuted(){
    std::vector <Process*> addressToPush_ReadyQueue;
    std::vector <Process*> addressToPush_ListR;
    int curTime = 0;
    int tempQuantum = quantumTime;
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    while (true){
        if (checkOutRR(processes) == true){
            break;
        }
        // Put process into CPU
        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                readyQueue.push_back(&processes[i]);
            }
        }

        if (tempQuantum == 0){
            if (readyQueue.size() > 1){
                std::vector <Process*> swap;
                swap.push_back(readyQueue[0]);
                readyQueue.erase(readyQueue.begin());
                readyQueue.push_back(swap[0]);
            }
            tempQuantum = quantumTime;
        }

        checkToPushRR(addressToPush_ListR, listR);
        checkToPushRR(addressToPush_ReadyQueue, readyQueue);

        if  (!readyQueue.empty()){
            CPU.push_back(readyQueue[0]->name);
            readyQueue[0]->burstTime[readyQueue[0]->status] --;
            tempQuantum--;
            if (readyQueue[0]->burstTime[readyQueue[0]->status] == 0){
                readyQueue[0]->status++;
                tempQuantum = quantumTime;
                if (readyQueue[0]->status < readyQueue[0]->burstTime.size()){
                    addressToPush_ListR.push_back(readyQueue[0]);
                }
                readyQueue.erase(readyQueue.begin());
            }
        }
        else {
            CPU.push_back(0);
        }

        if (!listR.empty()){
            R.push_back(listR[0]->name);
            listR[0]->burstTime[listR[0]->status]--;
            if (listR[0]->burstTime[listR[0]->status] == 0){
                listR[0]->status++;
                if (listR[0]->status < listR[0]->burstTime.size()){
                    addressToPush_ReadyQueue.push_back(listR[0]);
                }
                listR.erase(listR.begin());
            }
        }
        else {
            R.push_back(0);
        }
        curTime++;
    }
    calTurnaroundTime();
    calWaitingTime();
}