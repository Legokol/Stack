//
// Created by Николай on 15.02.2020.
//

#include "Stack.h"
#include "Subvector.h"


SubVector::SubVector() {
    mas = new int[0];
    top = 0;
    capacity = 0;
}

SubVector::~SubVector() {
    delete[] mas;
}

void SubVector::resize(unsigned int new_capacity) {
    int *new_mas;
    new_mas = new int[new_capacity];
    for (unsigned int i = 0; i < top; i++)
        new_mas[i] = mas[i];
    delete[] mas;
    mas = new_mas;
    capacity = new_capacity;
}

void SubVector::push_back(int d) {
    if (top < capacity) {
        top++;
        mas[top-1] = d;
        return;
    }
    resize(capacity + 1);
    top++;
    mas[top-1] = d;
}

int SubVector::pop_back() {
    top--;
    return mas[top];
}

void SubVector::shrink_to_fit() {
    resize(top);
}

void SubVector::clear() {
    top = 0;
}


