#include "CPUScheduler.h"
 
 void Scheduler::exportData(std::string filename){
    std::ofstream os(filename, std::ios::out);
    if (!os){
        std::cout <<"Can't open file out \n";
        return; 
    }
    for (int i = 0; i < CPU.size(); i++){
        if (CPU[i] == 0){
            os << "_ ";
        }
        else {
            os << CPU[i] << " ";
        }
    }
    os << "\n";

    for (int i = 0; i < R.size(); i++){
        if (R[i] == 0){
            os << "_ ";
        }
        else {
            os << R[i] << " ";
        }
    }
    os << "\n";

    for (int i = 0; i < processes.size(); i++){
        os <<processes[i].turnaroundTime << " ";
    }
    os << std::endl;
    for (int i = 0; i < processes.size(); i++){
        os <<processes[i].waitingTime << " ";
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
    // Idea: store the starts and ends of each curriculum and minus which is not waiting time.
    for (int i = 0; i < processes.size();i++){
        std::vector <int> posInCPU; 
        // index 0 is used to calculate waitingTime by substracting it with arrivalTime  
        // others are used to calculate waiting time for the curriculums.
        if (processes[i].name == CPU[0]){
            posInCPU.push_back(0);
            if (CPU[1] != processes[i].name){
                posInCPU.push_back(0);
            }
        }
        // Save position of processes in CPU
        for (int j = 1; j < CPU.size() - 1; j++){
            if(posInCPU.empty()){
                if (CPU[j] == processes[i].name){
                    posInCPU.push_back(j);
                }
                // Case: P stand alone
                if (CPU[j] == processes[i].name && CPU[j+1] != processes[i].name){
                    posInCPU.push_back(j);
                }
            }
            else {
                if ((CPU[j] == processes[i].name && CPU[j -1] != processes[i].name) && (CPU[j] == processes[i].name && CPU[j + 1] != processes[i].name)){
                    posInCPU.push_back(j);

                }
                if ((CPU[j] == processes[i].name && CPU[j -1] != processes[i].name) || (CPU[j] == processes[i].name && CPU[j + 1] != processes[i].name)){
                    posInCPU.push_back(j);
                }
            }
        }
        // Index last: case numbers of CPU > numbers of Resources
        if (processes[i].name == CPU[CPU.size() -1] && CPU[CPU.size() - 2] != processes[i].name){
            posInCPU.push_back(CPU.size() -1);
        }
        // Save position of processes in Resources
        int temp = (posInCPU.size() - 1) /2; // numbers of curriculum
        // That mean we care about index 1 -> index 2. index 3 -> index 4 .....
        int indexPosCPU = 1; // only takes odd index to calculate waiting time -bc it seperates into curriculum. 
        for (int j = 1; j <= temp; j++){
            bool flag = false;
            for (int k = posInCPU[indexPosCPU] + 1; k <= posInCPU[indexPosCPU +1]; k++){
                if (R[k] == processes[i].name && R[k+1] != processes[i].name){
                    processes[i].waitingTime += posInCPU[indexPosCPU+1] - k - 1;
                    flag = true; 
                }
            }
            // Case: No process in Resources at this curriculum
            if (flag == false){
                processes[i].waitingTime += posInCPU[indexPosCPU+1] - posInCPU[indexPosCPU] - 1;
            }
            indexPosCPU += 2; 
        }
        // Finally, add up the number of times the process first ran minus arrTime
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