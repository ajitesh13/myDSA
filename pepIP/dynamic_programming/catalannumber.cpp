#include <bits/stdc++.h>
using namespace std;
const int MAX = 10e5;
int catalan[MAX];
int MOD = INT_MAX;

void cat(int n) {
    catalan[0] = catalan[1] = 1;
    cout << catalan[0] << ' ' << catalan[1] << ' ';
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j<i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1])%MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
        cout << catalan[i] << ' ';
    }
}

int main() {
    int n = 10;
    cat(n);
    return 0;
}