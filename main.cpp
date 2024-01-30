#include "CPUScheduling.h"

int main(){
    std::vector <Process> processes;
    std::vector <int> burstTimeP1 {3,3,4};
    std::vector <int> burstTimeP2 {4};
    std::vector <int> burstTimeP3 {3,3};
    Process p1(1, 5, burstTimeP1);
    Process p2(2, 3, burstTimeP2);
    Process p3(3, 2, burstTimeP3);
    processes.push_back(p1);
    processes.push_back(p2);
    processes.push_back(p3);
    std::vector <int> test;

    FCFS_Excuted(processes);
    return 0;
}