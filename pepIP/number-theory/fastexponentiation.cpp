#include <bits/stdc++.h>
using namespace std;

long long fastexpo(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int m = 1000000007, a = 2, b = 3;
    cout << fastexpo(a, b, m) << '\n';
    return 0;
}