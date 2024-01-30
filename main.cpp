#include "CPUScheduler.h"
#include "Inputdata.h"

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Syntax: " << "22127106_22127229.exe" << " <INPUT_FILE> <OUTPUT_FILE> \n";
        return 0;
    }
    std::vector <Process> processes;
    int ID_Algorithm = 0;
    int quantumTime = 0;
    inputData(argv[1], processes, ID_Algorithm, quantumTime);

    if (ID_Algorithm == 1){
        FCFS(processes);
    }
    else if (ID_Algorithm == 2){

    }
    else if (ID_Algorithm == 3){
        
    }
    else if (ID_Algorithm == 4){
        
    }
    else {
        std::cout <<"Unknow ID Algorithm !" << std::endl;
        return 0;
    }

    
    return 0;
}