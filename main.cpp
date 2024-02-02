#include "Programming.h"

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Syntax: " << "22127106_22127229.exe" << " <INPUT_FILE> <OUTPUT_FILE> \n";
        return 0;
    }
    Programming programming;
    programming.run(argv[1], argv[2]);
    
    return 0;
}