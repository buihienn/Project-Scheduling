#include "CPUScheduling.h"


int main(){
    std::vector <Process> processes;
    std::vector <int> burstTimeP1 {7,3,3};
    std::vector <int> burstTimeP2 {5,2,5};
    std::vector <int> burstTimeP3 {3,3,3};
    Process p1(1, 0, burstTimeP1);
    Process p2(2, 1, burstTimeP2);
    Process p3(3, 2, burstTimeP3);
    processes.push_back(p1);
    processes.push_back(p2);
    processes.push_back(p3);
    std::vector <int> test; 
    // FCFS(processes, test, 0);
    // print (test);
    
    // std::vector <Process*> listCPU;
    // listCPU.push_back(&processes[0]);
    // listCPU[0]->burstTime[0]--;
    // std::cout <<processes[0].burstTime[0];

    // Do(processes);

    Test(processes);
    return 0;
}