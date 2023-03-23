#include "failure.h"

void Failure::error(int arg){
    if(arg != 3){
        HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);
        std::cout << "Must be 3 arguments: ./<filename> <filename1>.txt <filename2>.txt, where:" << std::endl;
        std::cout << "./<filename> - name of executable file" << std::endl;
        std::cout << "<filename1>.txt - name of 1st txt file" << std::endl;
        std::cout << "<filename2>.txt - name of 2nd txt file" << std::endl;
        std::cout << std::endl << "Program terminated due to invalid number of arguments" << "(" << arg << ")" << std::endl;
        SetConsoleTextAttribute(hConsoleHandle, 7);
        exit(0);
    }
}