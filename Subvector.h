#ifndef STACK_SUBVECTOR_H
#define STACK_SUBVECTOR_H

#include "Stack.h"

class Subvector : public Stack {
public:
    Subvector();

    ~Subvector();

    void resize(unsigned int new_capacity);

    void push_back(int d);

    int pop_back();

    unsigned int get_capacity();

    void shrink_to_fit();

    void clear();

private:
    int *mas;
    unsigned int top, capacity;
};


#endif //STACK_SUBVECTOR_H
