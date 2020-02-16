//
// Created by Николай on 16.02.2020.
//
#include "Stack.h"

#ifndef STACK_SUBFORWARDLIST_H
#define STACK_SUBFORWARDLIST_H


class SubForwardList : public Stack {
public:
    SubForwardList();

    ~SubForwardList();

    void push_back(int d);

    int pop_back();

    void push_forward(int d);

    int pop_forward();

    void push_where(unsigned int where, int d);

    int pop_where(unsigned int where);

    void erase_where(unsigned int where);

    unsigned int size();

    void clear();
private:
    SubForwardList *next;
    int data;
};


#endif //STACK_SUBFORWARDLIST_H
