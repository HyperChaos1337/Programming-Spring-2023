#pragma once

#include "windows.h"
#include "predefinitions.h"
#include "message_box.h"
#include <string>

using std::string;

long validation();
long validate_argument(int min, int max);
string validate_string(const string& message, bool validate);
void choice(char& YN);
bool is_overflow(double d);