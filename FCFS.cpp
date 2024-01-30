#include "FCFS.h"

bool checkOut(std::vector <Process>& processes){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            return false;
        }
    }
    return true;
}

void checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination){
    if (!address.empty()){
        destination.push_back(address[0]);
        address.pop_back();
    }
}

void FCFS(std::vector <Process> &processes){
    std::vector <Process*> readyQueue; // In Ready Queue or in processing
    std::vector <Process*> listR; // In Wait list or processing
    std::vector <int> CPU; // display name of Process at time
    std::vector <int> R; // display name of Process at time
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
    calTurnaroundTime(processes, CPU, R);
    calWaitingTime(processes, CPU, R);
    exportData(CPU,R,processes);
}   
