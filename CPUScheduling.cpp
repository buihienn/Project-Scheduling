#include "CPUScheduling.h"

void print(std::vector <int> t){
    for (int i = 0; i < t.size(); i++){
        if (t[i] == 0){
            std::cout << "- ";
        }
        else {
            std::cout << t[i] << " ";
        }
    }
    std::cout << "\n" << t.size();
}


// void FCFS(std::vector <Process> &processes,  std::vector <int> &timeLine, int count){

//     int curTime = 0;
//     for (int i = 0; i < processes.size(); i++){
//         // int tempWaitingTime = std::max(0, curTime - processes[i].getArrTime());
//         int tempWaitingTime = 0;
//         int temp = 0;
//         if (processes[i].getArrTime() - curTime > 0){
//             temp = processes[i].getArrTime() - curTime;
//             curTime += processes[i].getArrTime() - curTime + processes[i].getBurstTime(count);
//         }
//         else {
//             tempWaitingTime = curTime - processes[i].getArrTime();
//             curTime += processes[i].getBurstTime(count);
//         }
//         int waitingTime = processes[i].getWaitingTime() + tempWaitingTime;
//         int turnaroundTime = waitingTime + processes[i].getTurnaroundTime() + processes[i].getBurstTime(count);

//         processes[i].setWaitingTime(waitingTime);
//         processes[i].setTurnAroundTime(turnaroundTime);

//         for (int j = 0; j < temp; j++) {
//             // std::cout << "- ";
//             timeLine.push_back(0);
//         }
//         for (int j = 0; j < processes[i].getBurstTime(count); ++j) {
//             // std::cout << processes[i].getName() << " ";
//             timeLine.push_back(processes[i].getName());
//         }
//         // std::cout <<"Turn vs Waitingtime: \n";
//         // std::cout <<turnaroundTime << " - " << tempWaitingTime << " " << waitingTime << " - " << curTime <<"\n";
//         // Update current time
//     }
// }

void Register(std::vector <Process> &processes, std::vector <int> &timeR, int count){

}

// bool checkOut(std::vector <Process> processes){
//     for (int i = 0; i < processes.size(); i++){
//         if (processes[i].getBurstTime(processes[i].getNumBurstTime() -1 ) != 0){
//             return false;
//         }
//     }
//     return true;
// }

// void Do(std::vector <Process> &processes){
//     std::vector <Process*> listCPU; // In Ready Queue or in processing
//     std::vector <Process*> listR; // In Wait list or processing
//     std::vector <int> CPU; // display name of Process at time
//     std::vector <int> R; // display name of Process at time
//     // Sort arrivalTime
//     sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
//         return a.getArrTime() <= b.getArrTime();
//     });

//     int curTime = 0;
//     while(true){
//         if (checkOut(processes) == true)
//             break;
//         // Put process into CPU
//         for (int i = 0; i < processes.size();i ++){
//             if (processes[i].getArrTime() == curTime){
//                 listCPU.push_back(&processes[i]);
//                 processes[i].setStatus(1);
//             }
//         }
//         if (!listCPU.empty()){
//             CPU.push_back(listCPU[0]->getName());
//             listCPU[0]->BurstTimeSub(listCPU[0]->getStatus()); // burtTime-- 
//             if (listCPU[0]->getBurstTime(listCPU[0]->getStatus()) == 0){
//                 listCPU[0]->setStatus(listCPU[0]->getStatus() + 1);
//                 listCPU.erase(listCPU.begin());
//             }
//         }
//         else {
//             CPU.push_back(0);
//         }
        
//     }

// }   

void checkOut(std::vector <Process>& processes, bool &check){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            check == false;
            return;
        }
    }
    check == true;
}

void Do(std::vector <Process> &processes){
    std::vector <Process*> listCPU; // In Ready Queue or in processing
    std::vector <Process*> listR; // In Wait list or processing
    std::vector <int> CPU; // display name of Process at time
    std::vector <int> R; // display name of Process at time
    // Sort arrivalTime
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    bool check =false;
    int curTime = 0;
    while(true){
        checkOut(processes, check);
        if (check == true){
            std::cout <<"xx";
            break;
        }

        // Put process into CPU
        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                listCPU.push_back(&processes[i]);
            }
        }
        if (!listCPU.empty()){
            CPU.push_back(listCPU[0]->name);
            listCPU[0]->burstTime[listCPU[0]->status]--; // burstTime-- 
            std::cout <<listCPU[0]->burstTime[2] << " ";
            if (listCPU[0]->burstTime[listCPU[0]->status] == 0){
                listCPU[0]->status++;
                if (listCPU[0]->status < listCPU[0]->burstTime.size()){
                    listR.push_back(listCPU[0]);
                }
                listCPU.erase(listCPU.begin());
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
                    listCPU.push_back(listR[0]);
                }
                listR.erase(listR.begin());
            }
        }
        else {
            R.push_back(0);
        }
        curTime++;
    }

    print(CPU);
    std::cout <<std::endl;
    print(R);
}   

void Test(std::vector <Process> &processes){
    std::vector <Process*> listCPU; // In Ready Queue or in processing
    std::vector <Process*> listR; // In Wait list or processing
    std::vector <int> CPU; // display name of Process at time
    std::vector <int> R; // display name of Process at time
    // Sort arrivalTime
    sort(processes.begin(), processes.end(), [](Process& a,Process& b) {
        return a.arrTime <= b.arrTime;
    });
    int curTime = 0;
    bool check = false;
    for (int k = 0; k < 27; k++){
        for (int i = 0; i < processes.size();i ++){
            if (processes[i].arrTime == curTime){
                listCPU.push_back(&processes[i]);
            }
        }
        if (!listCPU.empty()){
            // std::cout << listCPU[0]->burstTime[0];
            CPU.push_back(listCPU[0]->name);
            listCPU[0]->burstTime[listCPU[0]->status]--; // burstTime-- 
            if (listCPU[0]->burstTime[listCPU[0]->status] == 0){
                listCPU[0]->status++;
                // std::cout <<listCPU[0]->status << " ";
                if (listCPU[0]->status < listCPU[0]->burstTime.size()){
                    listR.push_back(listCPU[0]);
                    check = true;
                }
                listCPU.erase(listCPU.begin());
            }
            
        }
        else {
            CPU.push_back(0);
        }
        if (!listR.empty() && check == true){
            R.push_back(0);
            check = false;
        }
        else if (!listR.empty()){
            R.push_back(listR[0]->name);
            listR[0]->burstTime[listR[0]->status]--;
            // std::cout <<listR[0]->burstTime[1] << " ";
            if (listR[0]->burstTime[listR[0]->status] == 0){
                listR[0]->status++;
                if (listR[0]->status < listR[0]->burstTime.size()){
                    listCPU.push_back(listR[0]);
                }
                listR.erase(listR.begin());
            }
        }
        else {
            R.push_back(0);
        }
        curTime++;
    }
    print(CPU);
    std::cout <<"\n";
    print(R);
}