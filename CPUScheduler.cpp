#include "CPUScheduler.h"
 
 void Scheduler::exportData(){
    for (int i = 0; i < CPU.size(); i++){
        if (CPU[i] == 0){
            std::cout << "_ ";
        }
        else {
            std::cout << CPU[i] << " ";
        }
    }
    std::cout << "\n" << CPU.size() << "\n";

    for (int i = 0; i < R.size(); i++){
        if (R[i] == 0){
            std::cout << "_ ";
        }
        else {
            std::cout << R[i] << " ";
        }
    }
    std::cout << "\n" << R.size() << "\n";

    for (int i = 0; i < processes.size(); i++){
        std::cout <<processes[i].turnaroundTime << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < processes.size(); i++){
        std::cout <<processes[i].waitingTime << " ";
    }
}

void Scheduler::calTurnaroundTime(){
    for (int i = 0; i < processes.size();i ++){
        int maxCPU = 0;
        int maxR = 0;
        for (int j = CPU.size() - 1; j >= 0l; j--){
            if (CPU[j] == processes[i].name){
                maxCPU = j;
                break;
            }
        }
        for (int j = R.size() - 1; j >= 0l; j--){
            if (R[j] == processes[i].name){
                maxR = j;
                break;
            }
        }
        processes[i].turnaroundTime = std::max(maxCPU, maxR) - processes[i].arrTime + 1;
    }
}

void Scheduler::calWaitingTime(){
    // Y tuong luu cac doan P ket thuc va Tiep tuc chay lai roi tru di cac noi khong phai waiting!
    for (int i = 0; i < processes.size();i++){
        std::vector <int> posInCPU; // index 0 is used to cal waitingTime of arrivalTime - // others is cal waiting for other processing.
        // Index 0 
        if (processes[i].name == CPU[0]){
            posInCPU.push_back(0);
            if (CPU[1] != processes[i].name){
                posInCPU.push_back(0);
            }
        }
        // Save pos process in CPU
        for (int j = 1; j < CPU.size() - 1; j++){
            if(posInCPU.empty()){
                if (CPU[j] == processes[i].name){
                    posInCPU.push_back(j);
                }
                // Case: P is alone
                if (CPU[j] == processes[i].name && CPU[j+1] != processes[i].name){
                    posInCPU.push_back(j);
                }
            }
            else {
                if ((CPU[j] == processes[i].name && CPU[j -1] != processes[i].name) || (CPU[j] == processes[i].name && CPU[j + 1] != processes[i].name)){
                    posInCPU.push_back(j);
                }
            }
        }
        // Index last
        if (processes[i].name == CPU[CPU.size() -1] && CPU[CPU.size() - 2] != processes[i].name){
            posInCPU.push_back(CPU.size() -1);
        }
        // Save pos process in Resources
        int temp = (posInCPU.size() - 1) /2; // So khoang can tinh
        int indexPosCPU = 1; // chi lay so le vi posInCPU[0] la de tinh ArrivalTime
        for (int j = 1; j <= temp; j++){
            bool flag = false;
            for (int k = posInCPU[indexPosCPU] + 1; k <= posInCPU[indexPosCPU +1]; k++){
                if (R[k] == processes[i].name && R[k+1] != processes[i].name){
                    processes[i].waitingTime += posInCPU[indexPosCPU+1] - k - 1;
                    flag = true;
                }
            }
            // Case: Khong co  P trong R o khoang nay
            if (flag == false){
                processes[i].waitingTime += posInCPU[indexPosCPU+1] - posInCPU[indexPosCPU] - 1;
            }
            indexPosCPU += 2; 
        }
        // Cal WaitingTime
        processes[i].waitingTime += posInCPU[0] - processes[i].arrTime;
    }
}


bool Scheduler::checkOut(std::vector <Process>& processes){
    for (int i = 0; i < processes.size(); i++){
        if (processes[i].burstTime.back() != 0){
            return false;
        }
    }
    return true;
}

void Scheduler::checkToPush(std::vector <Process*> &address, std::vector <Process*> &destination){
    if (!address.empty()){
        destination.push_back(address[0]);
        address.pop_back();
    }
}