#include <iostream>
#include "Stack.h"
#include "Subvector.h"

using namespace std;

int main() {
    Stack *s;
    s = new SubVector();
    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        s->push_back(d);
    }
    for (int i = 0; i < n; i++) {
        cout << s->pop_back() << ' ';
    }
    return 0;
}
