#ifndef STACK_SUBFORWARDLIST_H
#define STACK_SUBFORWARDLIST_H

#include "Stack.h"

class Subforwardlist : public Stack {
public:
    Subforwardlist();

    ~Subforwardlist();

    void push_back(int d);

    int pop_back();

    void push_forward(int d);

    int pop_forward();

    void push_where(unsigned int where, int d);

    int pop_where(unsigned int where);

    void erase_where(unsigned int where);

    unsigned int get_size();

    void clear();
private:
    Subforwardlist *next;
    int data;
};


#endif //STACK_SUBFORWARDLIST_H
