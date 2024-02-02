#include "Inputdata.h"

void inputData(std::string filename, std::vector <Process> &processes,int &ID_Algorithm, int &quantumTime){
    std::fstream filein (filename, std::ios::in);
    if (!filein){
        std::cout << "Can't open file in!" << std::endl;
        return;
    }

    filein >> ID_Algorithm;
    if (ID_Algorithm == 2){
        filein >> quantumTime;
    }
    int numProcess = 0;
    filein >> numProcess;
    filein.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < numProcess; i++){
        std::string line;
        std::getline(filein, line); 
        std::stringstream s(line);
        int arrTime = 0;
        s >> arrTime;
        std::vector <int> burstTime;
        int tempBurstTime = 0;
        while (s >> tempBurstTime){
            burstTime.push_back(tempBurstTime);
        } 
        processes.push_back(Process(i + 1, arrTime, burstTime));
    }
}