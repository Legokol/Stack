//
// Created by Николай on 15.02.2020.
//

#include "Stack.h"
#ifndef STACK_SUBVECTOR_H
#define STACK_SUBVECTOR_H


class SubVector : public Stack {
public:
    SubVector();

    ~SubVector();

    void resize(unsigned int new_capacity);

    void push_back(int d);

    int pop_back();

    void shrink_to_fit();

    void clear();

private:
    int *mas;
    unsigned int top, capacity;
};


#endif //STACK_SUBVECTOR_H
