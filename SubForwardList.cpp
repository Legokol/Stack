//
// Created by Николай on 16.02.2020.
//

#include "Stack.h"
#include "SubForwardList.h"
#include <iostream>

using namespace std;

SubForwardList::SubForwardList() {
    data = 0;
    next = NULL;
}

SubForwardList::~SubForwardList() {
}

unsigned int SubForwardList::size() {
    unsigned int s = 0;
    SubForwardList *n = this;
    while (n->next != NULL) {
        s++;
        n = n->next;
    }
    return s;
}

void SubForwardList::push_back(int d) {
    SubForwardList *s = this;
    while (s->next != NULL)
        s = s->next;
    SubForwardList *n = new SubForwardList();
    n->data = d;
    s->next = n;
}

int SubForwardList::pop_back() {
    SubForwardList *s = this;
    while (s->next->next != NULL)
        s = s->next;
    int d = s->next->data;
    delete s->next;
    s->next = NULL;
    return d;
}

void SubForwardList::push_forward(int d) {
    SubForwardList *n = new SubForwardList();
    n->data = d;
    n->next = next;
    next = n;
    delete n;
}

int SubForwardList::pop_forward() {
    int d = next->data;
    next = next->next;
    return d;
}

void SubForwardList::push_where(unsigned int where, int d) {
    if (where > size()) {
        cout << "Can't push. Number is higher than size" << endl;
        return;
    }
    SubForwardList *s = this;
    for (unsigned int i = 1; i < where; i++)
        s = s->next;
    SubForwardList *n = new SubForwardList();
    n->data = d;
    n->next = s->next;
    s->next = n;
}

int SubForwardList::pop_where(unsigned int where) {
    if (where > size()) {
        cout << "Can't pop. Number is higher than size" << endl;
        return INT_MAX;
    }

}

void SubForwardList::erase_where(unsigned int where) {

}

void SubForwardList::clear() {

}
