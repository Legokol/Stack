//
// Created by Николай on 15.02.2020.
//

#include "Stack.h"

class SubVector : public Stack {
public:
    SubVector() {
        mas = new int[0];
        top = 0;
        capacity = 0;
    }

    ~SubVector() {
        delete[] mas;
    }

    void resize(unsigned int new_capacity) {
        int *new_mas;
        new_mas = new int[new_capacity];
        for (unsigned int i = 0; i < top; i++)
            new_mas[i] = mas[i];
        delete[] mas;
        mas = new_mas;
        capacity = new_capacity;
    }

    void push_back(int d) {
        if (top < capacity) {
            top++;
            mas[top] = d;
            return;
        }
        resize(capacity + 1);
        top++;
        mas[top] = d;
    }

    int pop_back() {
        top--;
        return mas[top + 1];
    }

    void shrink_to_fit() {
        resize(top);
    }

    void clear() {
        top = 0;
    }

private:
    int *mas;
    unsigned int top, capacity;
};
