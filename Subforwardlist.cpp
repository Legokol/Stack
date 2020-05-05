#include "Subforwardlist.h"

Subforwardlist::Subforwardlist() {
    size = 0;
    data = 0;
    next = nullptr;
}

Subforwardlist::~Subforwardlist() {
    clear();
}

unsigned int Subforwardlist::get_size() {
    return size;
}

void Subforwardlist::push_back(int d) {
    Subforwardlist *s = this;
    while (s->next != nullptr)
        s = s->next;
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    s->next = n;
    size++;
}

int Subforwardlist::pop_back() {
    if (next == nullptr)
        return 0;
    Subforwardlist *s = this;
    while (s->next->next != nullptr)
        s = s->next;
    int d = s->next->data;
    delete s->next;
    s->next = nullptr;
    size--;
    return d;
}

void Subforwardlist::push_forward(int d) {
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    n->next = next;
    next = n;
    size++;
}

int Subforwardlist::pop_forward() {
    if (next == nullptr)
        return 0;
    Subforwardlist *s = next;
    int d = s->data;
    next = s->next;
    s->next = nullptr;
    delete s;
    size--;
    return d;
}

void Subforwardlist::push_where(unsigned int where, int d) {
    if (where >= size || where < 0)
        return;
    Subforwardlist *s = this;
    for (unsigned int i = 0; i < where; i++)
        s = s->next;
    Subforwardlist *n = new Subforwardlist();
    n->data = d;
    n->next = s->next;
    s->next = n;
    size++;
}

int Subforwardlist::pop_where(unsigned int where) {
    if (where >= size || where < 0)
        return 0;
    Subforwardlist *s = this;
    for (unsigned int i = 0; i < where; i++)
        s = s->next;
    Subforwardlist *n = s->next;
    int d = n->data;
    s->next = n->next;
    n->next = nullptr;
    delete n;
    size--;
    return d;
}

void Subforwardlist::erase_where(unsigned int where) {
    if (where >= size || where < 0)
        return;
    Subforwardlist *s = this;
    for (unsigned int i = 0; i < where; i++)
        s = s->next;
    Subforwardlist *n = s->next;
    s->next = n->next;
    n->next = nullptr;
    delete n;
    size --;
}

void Subforwardlist::clear() {
    if (next == nullptr)
        return;
    Subforwardlist *s = next, *c = next;
    while (s->next != nullptr) {
        s = s->next;
        c->next = nullptr;
        delete c;
        c = s;
    }
    delete c;
    size = 0;
    next = nullptr;
}
