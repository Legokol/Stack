#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>

class Stack {
public:
    virtual ~Stack() {};

    virtual void push_back(int d) = 0;

    virtual int pop_back() = 0;
};


#endif //STACK_STACK_H
