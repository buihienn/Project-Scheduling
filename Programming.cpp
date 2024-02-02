#include "Programming.h"

void Programming::run(char *input, char* output){
    Inputdata inputData(input);
    Scheduler *scheduler = NULL;

    if (inputData.ID_Algorithm == 1){
        scheduler = new FCFS(inputData.processes);
    }
    else if (inputData.ID_Algorithm == 2){
        scheduler = new RoundRobin(inputData.processes, inputData.quantumTime);
    }
    else if (inputData.ID_Algorithm == 3){
        scheduler = new SJF(inputData.processes);
    }
    else if (inputData.ID_Algorithm == 4){
        scheduler = new SRTN(inputData.processes);
    }
    else {
        std::cout <<"Unknow ID Algorithm !" << std::endl;
        return;
    }
    scheduler->executed();
    scheduler->exportData(output);
    delete scheduler;
}