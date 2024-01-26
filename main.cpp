#include "CPUScheduling.h"


int main(){
    std::vector <Process> processes;
    Process p1(1, 0, 6);
    Process p2(2, 8, 5);
    Process p3(3, 9, 3);
    processes.push_back(p1);
    processes.push_back(p2);
    processes.push_back(p3);
    FCFS(processes);
    return 0;
}