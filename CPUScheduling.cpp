#include "CPUScheduling.h"

void UpdateWaitingTimeFCFS(std::vector <Process> &processes, int timeLine){
    // for (int i = 1; i < processes.size(); i++){
    //     int tempWaitingTime = 0;
    //     if (processes[i].getArrTime() >= timeLine){
    //         tempWaitingTime = processes[i].getTurnaroundTime();
    //     }
    //     else {
    //         tempWaitingTime = processes[i-1].getBurstTime() + processes[i-1].getWaitingTime() - processes[i].getArrTime();
    //     }
    //     processes[i].setWaitingTime(tempWaitingTime);
    // }
    for (int i = 0; i < processes.size(); i++){
        processes[i].setWaitingTime(processes[i].getTurnaroundTime() - processes[i].getBurstTime());
    }
    std::cout <<"Wait: " << std :: endl;
    for (int i = 0; i < processes.size(); i++){
        std::cout <<processes[i].getWaitingTime() << std:: endl;
    }
}

int TimeLineEachFCFS(std::vector <Process> processes){
    int time = processes[0].getBurstTime();
    for (int i = 1; i < processes.size(); i++){
        if (processes[i].getArrTime() >= time){
            time = processes[i].getArrTime();
        }
        time += processes[i].getBurstTime();
    }
    return time;
}

void UpdateTurnaroundTime(std::vector <Process> &processes){
    int time = processes[0].getBurstTime();
    processes[0].setTurnAroundTime(time);
    for (int i = 1; i < processes.size(); i++){
        if (processes[i].getArrTime() >= time){
            time = processes[i].getArrTime();
        }
        time += processes[i].getBurstTime();
        processes[i].setTurnAroundTime(time - processes[i].getArrTime());
    }
    std::cout <<"Turn: " << std :: endl;
    for (int i = 0; i < processes.size(); i++){
        std::cout <<processes[i].getTurnaroundTime() << std:: endl;
    }
}



void FCFS (std::vector <Process> processes){
    int n = 0;
    
    // Process p1("P1", 0, 24);
    // Process p2("P2", 1, 5);
    // Process p3("P3", 2, 3);
    // processes.push_back(p1);
    // processes.push_back(p2);
    // processes.push_back(p3);
    sort(processes.begin(), processes.end(), [](Process &a,Process &b) {
        return a.getArrTime() < b.getArrTime();
    });

    int timeLine = TimeLineEachFCFS(processes);
    UpdateTurnaroundTime(processes);
    UpdateWaitingTimeFCFS(processes, timeLine);
   
    
    std::cout <<"Time line: " << timeLine << std::endl;
    int k = 0;
    for (int i = 0; i < timeLine; i++){
        for (int j = 0; j < processes[k].getBurstTime(); j++){
            std::cout <<processes[k].getName() << " ";
            i++;
        }
        k++;
        int temp = processes[k-1].getTurnaroundTime() + processes[k-1].getArrTime();
        if (processes[k].getArrTime() > temp){
            for (int j = 0; j < (processes[k].getArrTime() - temp);j++){
                if (i >= timeLine){
                    break;
                }
                std::cout <<"-";
                i++;
            }
        }
    }
}


