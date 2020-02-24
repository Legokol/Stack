#include <iostream>
#include "Stack.h"
#include "Subvector.h"
#include "SubForwardList.h"

using namespace std;

int main() {
    SubForwardList *s;
    s = new SubForwardList();
    int n, d, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        s->push_back(d);
    }
    //cout << s->size();
    cin >> w;
    s->erase_where(w);
    for (int i = 0; i < n - 1; i++)
        cout << s->pop_forward() << ' ';
    return 0;
}
