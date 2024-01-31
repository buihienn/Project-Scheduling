#include "SJF.h"

SJF::SJF(std::vector <Process> &processes){
    this->processes = processes;
}

bool checkOutSJF(std::vector <Process>& processes){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            return false;
        }
    }
    return true;
}

void SJF::excuted(){
    
    std::vector<Process*> temp1;
    // Sort arrivalTime
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    
    int curTime = 0;
    bool check = false;
    while(true){
        if (checkOutSJF(processes) == true){
            break;
        }

        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                readyQueue.push_back(&processes[i]);//
                if(readyQueue.size()>0&& check==true){//sort khi mà 1 process ketthuc,1 process duoc push vao sort ngay 2 process
                    sort(readyQueue.begin(), readyQueue.end(), [](Process *&a,Process *&b) {
                        if(a->status==b->status) return a->burstTime[a->status] <= b->burstTime[b->status];
                        else if(a->status<b->status)return true;//neu status be hon thi xep a trc b
                        else return false;//neu status a>b thi xep b trc a
                    });
                    check=false;
                }
               
                
            }
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
                check=true;

                if(readyQueue.size()>0&& check==true){// khi ma vua moi pop 1 process, sort 2 cai so san trong readyqueue
                    sort(readyQueue.begin(), readyQueue.end(), [](Process *&a,Process *&b) {
                        if(a->status==b->status) return a->burstTime[a->status] <= b->burstTime[b->status];
                        else if(a->status<b->status)return true;//neu status be hon thi xep a trc b
                        else return false;//neu status a>b thi xep b trc a
                    });
                }
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
        if(!temp1.empty()){
            listR.push_back(temp1[0]);
            temp1.pop_back();
        }
    }
    calTurnaroundTime();
    calWaitingTime();
}