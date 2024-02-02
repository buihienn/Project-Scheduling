#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

#include "process.h"


class Inputdata {
public:
    std::vector <Process> processes;
    int ID_Algorithm;
    int quantumTime;
    Inputdata (const std::string &filename);

    void readData(const std::string &filename);
};

// void inputData(std::string filename, std::vector <Process> &processes,int &ID_Algorithm, int &quantumTime);