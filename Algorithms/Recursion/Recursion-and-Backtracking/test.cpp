#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i=0; i<8; i++) {
        if (__builtin_popcount(i) == 2) {
            cout << i << '\n';
        }
    }
}