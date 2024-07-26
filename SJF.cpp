#include "SJF.h"

SJF::SJF(std::vector <Process> &processes){
    this->processes = processes;
}

void SJF::executed(){
    
    std::vector<Process*> tempR;
    std::vector<Process*> tempReadyQueue;
    
    int curTime = 0;
    bool check = false;
    while(true){
        if (checkOut(processes) == true)
        {
            break;
        }
        
        for (int i = 0; i < processes.size();i ++)
        {
            if (processes[i].arrTime == curTime){
                readyQueue.push_back(&processes[i]);
            }
        }
        
        checkToPush(tempR, listR);
        checkToPush(tempReadyQueue, readyQueue);
        if(check==true)
        {
            if(readyQueue.size()>1){
                sort
                (readyQueue.begin(), readyQueue.end(), [](Process *&a,Process *&b)
                    {
                        if(a->burstTime[a->status] < b->burstTime[b->status])
                            return true;
                        else 
                            return false;
                    }
                );
                
            }
        }
        check=false;
        if (!readyQueue.empty())
        {
          
            CPU.push_back(readyQueue[0]->name);
            readyQueue[0]->burstTime[readyQueue[0]->status]--; // burstTime-- 

            if (readyQueue[0]->burstTime[readyQueue[0]->status] == 0){
                readyQueue[0]->status++;
                check=true;
                if (readyQueue[0]->status < readyQueue[0]->burstTime.size()){
                    tempR.push_back(readyQueue[0]);
                }
            
                readyQueue.erase(readyQueue.begin());
             

            }
            
        }
        else 
        {
            CPU.push_back(0);
        }
        
        if (!listR.empty())
        {
            R.push_back(listR[0]->name);
            listR[0]->burstTime[listR[0]->status]--;

            if (listR[0]->burstTime[listR[0]->status] == 0){
                listR[0]->status++;

                if (listR[0]->status < listR[0]->burstTime.size()){
                    tempReadyQueue.push_back(listR[0]);
                }

                listR.erase(listR.begin());
            }

        }
        else
        {
            R.push_back(0);
        }
        curTime++;
        
    }
    calTurnaroundTime();
    calWaitingTime();
}