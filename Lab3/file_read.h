#pragma once

#include <string>
#include <fstream>
#include <bitset>

using std::string;
using std::ofstream;
using std::ifstream;

void write_in_file(ofstream& output, const string& string);
std::string read_from_file(ifstream& input);
int read_int(ifstream& input);
bool check_key(ifstream& input, char key);
char read_key(ifstream& input);