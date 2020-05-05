#include "Subforwardlist.h"
#include <iostream>

using namespace std;

Subforwardlist::Subforwardlist() {
    data = 0;
    next = NULL;
}

Subforwardlist::~Subforwardlist() {
    unsigned int n = get_size();
    Subforwardlist **s = new Subforwardlist *[n + 1];
    Subforwardlist *c = this;
    s[0] = c;
    for (unsigned int i = 1; i < n + 1; i++) {
        c = c->next;
        s[i] = c;
    }
    delete[] s;
}

unsigned int Subforwardlist::get_size() {
    unsigned int s = 0;
    Subforwardlist *n = this;
    while (n->next != NULL) {
        s++;
        n = n->next;
    }
    return s;
}

void Subforwardlist::push_back(int d) {
    Subforwardlist *s = this;
    while (s->next != NULL)
        s = s->next;
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    s->next = n;
}

int Subforwardlist::pop_back() {
    Subforwardlist *s = this;
    while (s->next->next != NULL)
        s = s->next;
    int d = s->next->data;
    delete s->next;
    s->next = NULL;
    return d;
}

void Subforwardlist::push_forward(int d) {
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    n->next = next;
    next = n;
    delete n;
}

int Subforwardlist::pop_forward() {
    int d = next->data;
    next = next->next;
    return d;
}

void Subforwardlist::push_where(unsigned int where, int d) {
    if (where > get_size()) {
        cout << "Can't push. Number is higher than size" << endl;
        return;
    }
    Subforwardlist *s = this;
    for (unsigned int i = 1; i < where; i++)
        s = s->next;
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    n->next = s->next;
    s->next = n;
}

int Subforwardlist::pop_where(unsigned int where) {
    if (where > get_size()) {
        cout << "Can't pop. Number is higher than size" << endl;
        return INT_MAX;
    }
    Subforwardlist *s = this;
    for (unsigned int i = 1; i < where; i++)
        s = s->next;
    Subforwardlist *n = s->next;
    int d = n->data;
    s->next = n->next;
    delete n;
    return d;
}

void Subforwardlist::erase_where(unsigned int where) {
    if (where > get_size()) {
        cout << "Can't erase. Number is higher than size" << endl;
        return;
    }
    Subforwardlist *s = this;
    for (unsigned int i = 1; i < where; i++)
        s = s->next;
    Subforwardlist *n = s->next;
    s->next = n->next;
    delete n;
}

void Subforwardlist::clear() {
    unsigned int n = get_size();
    Subforwardlist **s = new Subforwardlist *[n];
    Subforwardlist *c = this;
    for (unsigned int i = 0; i < n; i++) {
        c = c->next;
        s[i] = c;
    }
    delete[] s;
    next = NULL;
}
