#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q, a, b;
    set<int> qheap;
    cin >> q;
    
    while(q > 0) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            qheap.insert(b);
        } else if (a == 2) {
            cin >> b;
            qheap.erase(b);
        } else {
            cout << *qheap.begin() << endl;
        }
        --q;
    }
    return 0;
}

