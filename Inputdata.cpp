#include "Inputdata.h"

// void inputData(std::string filename, std::vector <Process> &processes,int &ID_Algorithm, int &quantumTime){
//     std::fstream is (filename, std::ios::in);
//     if (!is){
//         std::cout << "Can't open file in!" << std::endl;
//         return;
//     }

//     is >> ID_Algorithm;
//     if (ID_Algorithm == 2){
//         is >> quantumTime;
//     }
//     int numProcess = 0;
//     is >> numProcess;
//     is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     for (int i = 0; i < numProcess; i++){
//         std::string line;
//         std::getline(is, line); 
//         std::stringstream s(line);
//         int arrTime = 0;
//         s >> arrTime;
//         std::vector <int> burstTime;
//         int tempBurstTime = 0;
//         while (s >> tempBurstTime){
//             burstTime.push_back(tempBurstTime);
//         } 
//         processes.push_back(Process(i + 1, arrTime, burstTime));
//     }
// }temp1


Inputdata::Inputdata(const std::string &filename){
    readData(filename);
}

void Inputdata::readData(const std::string &filename){
    std::fstream is (filename, std::ios::in);
    if (!is){
        std::cout << "Can't open file in!" << std::endl;
        return;
    }

    is >> ID_Algorithm;
    if (ID_Algorithm == 2){
        is >> quantumTime;
    }
    int numProcess = 0;
    is >> numProcess;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < numProcess; i++){
        std::string line;
        std::getline(is, line); 
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