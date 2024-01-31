#include "RoundRobin.h"
#include "FCFS.h"
#include "Inputdata.h"

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Syntax: " << "22127106_22127229.exe" << " <INPUT_FILE> <OUTPUT_FILE> \n";
        return 0;
    }
    std::vector <Process> processes;
    Scheduler *scheduler = NULL;
    int ID_Algorithm = 0;
    int quantumTime = 0;
    inputData(argv[1], processes, ID_Algorithm, quantumTime);

    if (ID_Algorithm == 1){
        scheduler = new FCFS(processes);
    }
    else if (ID_Algorithm == 2){
        scheduler = new RoundRobin(processes, quantumTime);
    }
    else if (ID_Algorithm == 3){
        
    }
    else if (ID_Algorithm == 4){
        
    }
    else {
        std::cout <<"Unknow ID Algorithm !" << std::endl;
        return 0;
    }
    scheduler->excuted();
    scheduler->exportData();
    delete scheduler;
    
    return 0;
}