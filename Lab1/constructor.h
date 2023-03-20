#ifndef PR_LAB1_CONSTRUCTOR_H
#define PR_LAB1_CONSTRUCTOR_H

#include "list.h"
#include <iostream>
#include <cctype>
#include <conio.h>
#include <limits>
#include <cwchar>

#define MAX_SIZE 20

class Constructor{
public:
    int size;
    List list;
public:
    void output();
    void length();
    void input();
    void insert_element();
    void remove_element();
    void partial_insert();
    void partial_removal();
    void list_removal();
    void list_reversing();
    void list_sorting();
};

#endif