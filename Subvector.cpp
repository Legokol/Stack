#include "Subvector.h"

Subvector::Subvector() {
    mas = new int[1];
    top = 0;
    capacity = 1;
}

Subvector::~Subvector() {
    delete[] mas;
}

void Subvector::resize(unsigned int new_capacity) {
    int *new_mas = new int[new_capacity];
    capacity = new_capacity;
    if (top > new_capacity)
        top = new_capacity;
    for (unsigned int i = 0; i < top; i++)
        new_mas[i] = mas[i];
    delete[] mas;
    mas = new_mas;
}

void Subvector::push_back(int d) {
    if (top < capacity) {
        top++;
        mas[top - 1] = d;
        return;
    }
    resize(capacity * 2);
    top++;
    mas[top - 1] = d;
}

int Subvector::pop_back() {
    if (top == 0)
        return 0;
        //throw std::runtime_error("Stack is empty");
    top--;
    return mas[top];
}

unsigned int Subvector::get_capacity() {
    return capacity;
}

void Subvector::shrink_to_fit() {
    resize(top);
}

void Subvector::clear() {
    top = 0;
}


