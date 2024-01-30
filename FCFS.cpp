#include "CPUScheduling.h"

bool checkOut(std::vector <Process>& processes){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            return false;
        }
    }
    return true;
}

void FCFS_Excuted(std::vector <Process> &processes){
    std::vector <Process*> readyQueue; // In Ready Queue or in processing
    std::vector <Process*> listR; // In Wait list or processing
    std::vector <int> CPU; // display name of Process at time
    std::vector <int> R; // display name of Process at time
    std::vector <Process*> temp1;
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
        if (!readyQueue.empty()){
            // std::cout << readyQueue[0]->burstTime[0];
            CPU.push_back(readyQueue[0]->name);
            readyQueue[0]->burstTime[readyQueue[0]->status]--; // burstTime-- 
            if (readyQueue[0]->burstTime[readyQueue[0]->status] == 0){
                readyQueue[0]->status++;
                if (readyQueue[0]->status < readyQueue[0]->burstTime.size()){
                    // listR.push_back(readyQueue[0]);
                    temp1.push_back(readyQueue[0]);
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
                    readyQueue.push_back(listR[0]);
                }
                listR.erase(listR.begin());
            }
        }
        else {
            R.push_back(0);
        }

        curTime++;
        
        if (!temp1.empty()){
            listR.push_back(temp1[0]);
            temp1.pop_back();
        }
    }
    calTurnaroundTime(processes, CPU, R);
    calWaitingTime(processes, CPU, R);
    print(CPU,R,processes);
}   
