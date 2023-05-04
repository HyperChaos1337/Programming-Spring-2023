#include "message_box.h"
#include "windows.h"
#include <iostream>

using std::cout;

void error(const string& message) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << message << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void info(const string& message) {
    cout << message << '\n';
}