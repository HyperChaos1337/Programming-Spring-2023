#include "validator.h"
#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;

long validation() {
    bool flag = false;
    double result;
    while (!flag) {
        if (scanf_s("%lf", &result)) {
            if (!is_overflow(result)) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << "Digit is out of bounds. Try again" << '\n';
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            }
            else flag = true;
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << "Invalid input. Try again" << '\n';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        }
        fflush(stdin);
    }
    return (long)result;
}

long validate_argument(int min, int max) {
    long result;
    do {
        result = validation();
        if (result > max || result < min) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << "Invalid input! Allowed value: " << min << " to " << max << '\n';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        }
    } while (result > max || result < min);
    return result;
}

string validate_string(const string& message, bool validate) {
    string str;
    info(message);
    cin >> str;
    if (validate) {
        while (str.empty()) {
            error("String must not be empty");
            cin >> str;
        }
    }
    return str;
}

void choice(char& YN) {
    bool exit = false;
    while (!exit) {
        fflush(stdin);
        YN = (char)getchar();
        fflush(stdin);
        if (YN == '1' || YN == '2') exit = true;
        else if (YN != ENTER) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << "Invalid input. Value must be 1 or 2" << '\n';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        }
    }
}

bool is_overflow(double d) {
    return d >= -2147483648 && d <= 2147483647;
}