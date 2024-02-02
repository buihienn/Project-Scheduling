#include "SRTN.h"

SRTN::SRTN(std::vector <Process> &processes){
    this->processes = processes;
}

void SRTN::excuted(){
    std::vector<Process*> temp1;
    std::vector<Process*> temp2;
    // Sort arrivalTime
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    
    int curTime = 0;
    
    while(true){
        if (checkOut(processes) == true){
            break;
        }

        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                readyQueue.push_back(&processes[i]);//
            }
        }
        checkToPush(temp1, listR);
        checkToPush(temp2, readyQueue);
        if(readyQueue.size()>1){
            sort
            (readyQueue.begin(), readyQueue.end(), [](Process *&a,Process *&b)
                {
                    if(a->burstTime[a->status] == b->burstTime[b->status])
                    {
                        return a->status >= b->status;
                    }
                    else if(a->burstTime[a->status] < b->burstTime[b->status])
                        return true;
                    else 
                        return false;
                }
            );
            
        }
        if (!readyQueue.empty()){
          
            CPU.push_back(readyQueue[0]->name);
            readyQueue[0]->burstTime[readyQueue[0]->status]--; // burstTime-- 

            if (readyQueue[0]->burstTime[readyQueue[0]->status] == 0){
                readyQueue[0]->status++;
                
                if (readyQueue[0]->status < readyQueue[0]->burstTime.size()){
                 
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
                    temp2.push_back(listR[0]);
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