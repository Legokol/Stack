//
// Created by Николай on 16.02.2020.
//

#include "Stack.h"

class SubForwardList : public Stack {
public:
    SubForwardList() {
        data = 0;
        next = nullptr;
    }

    ~SubForwardList() {
    }

    void push_back(int d) {
        if (next == nullptr) {
            SubForwardList *n = new SubForwardList();
            n->data = d;
            next = n;
            delete n;
            return;
        }
        next->push_back(d);
    }

    int pop_back() {
        if (next->next = nullptr) {
            int d = next->data;
            delete next;
            return d;
        }
        next->pop_back();
    }

    void push_forward(int d) {
        SubForwardList *n = new SubForwardList();
        n->data = d;
        n->next = next;
        next = n;
        delete n;
    }

    int pop_forward() {
        int d = next->data;
        next = next->next;
        return d;
    }

    void push_where(unsigned int where, int d);

    int pop_where(unsigned int where);

    void erase_where(unsigned int where);

    unsigned int size();

    void clear();

private:
    SubForwardList *next;
    int data;
};
