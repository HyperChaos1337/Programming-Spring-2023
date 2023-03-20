#ifndef PR_LAB1_LIST_H
#define PR_LAB1_LIST_H

#include <iostream>
#include "node.h"

class List{
public:
    Node *prev, *cur;
public:
    List();
    Node* get_root();
    void is_empty();
    unsigned list_length();
    void print();
    void push_back(long long int element);
    void push_front(long long int element);
    void insert(int index, long long int element);
    void pop_front();
    void pop_back();
    void remove(int index, unsigned length);
    void erase(unsigned length);
    Node* get_cur_element(int index);
    void add_elements(int start, int amount);
    void delete_elements(int start, int amount);
    void reverse();
    void sort();
};
#endif