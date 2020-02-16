//
// Created by Николай on 15.02.2020.
//
#include <iostream>
using namespace std;

class Stack {
public:
    virtual void push_back(int d) = 0;

    virtual int pop_back() = 0;
};
