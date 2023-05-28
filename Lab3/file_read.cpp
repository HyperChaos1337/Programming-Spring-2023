#include "file_read.h"
#include "predefinitions.h"
#include <iostream>

using std::bitset;

void write_in_file(ofstream& output, const string& string) {
    for (char i : string) {
        output << bitset<8>(i) << ' ';
    }
    output << bitset<8>(SPLIT_USUAL_VALUE) << ' ' << std::endl;
}

string read_from_file(ifstream& input) {
    string string, bs;
    char a;
    while (true) {
        input >> bs;
        a = bitset<8>(bs).to_ulong();
        if (a == 1) break;
        string += a;
    }
    return string;
}

int read_int(ifstream& input) {
    string data;
    input >> data;
    return bitset<16>(data).to_ulong();
}

bool check_key(ifstream& input, char key) {
    string data;
    input >> data;
    return key == bitset<8>(data).to_ulong();
}

char read_key(std::ifstream& input) {
    string data;
    input >> data;
    return std::bitset<8>(data).to_ulong();
}