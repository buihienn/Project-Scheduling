#include "FCFS.h"

FCFS::FCFS(std::vector <Process> &processes){
    this->processes = processes;
}

void FCFS::excuted(){
    std::vector <Process*> addressToPush_ReadyQueue;
    std::vector <Process*> addressToPush_ListR;
    // Sort arrivalTime
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    int curTime = 0;
    while(true){
        if (checkOut(processes) == true){
            break;
        }
        // Put process into CPU
        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                readyQueue.push_back(&processes[i]);
            }
        }
        checkToPush(addressToPush_ListR, listR);
        checkToPush(addressToPush_ReadyQueue, readyQueue);
        // CPU Run
        if (!readyQueue.empty()){
            CPU.push_back(readyQueue[0]->name);
            readyQueue[0]->burstTime[readyQueue[0]->status]--; // burstTime-- 
            if (readyQueue[0]->burstTime[readyQueue[0]->status] == 0){
                readyQueue[0]->status++;
                if (readyQueue[0]->status < readyQueue[0]->burstTime.size()){
                    addressToPush_ListR.push_back(readyQueue[0]);
                }
                readyQueue.erase(readyQueue.begin());
            }
        }
        else {
            CPU.push_back(0);
        }
        //Resources run
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

