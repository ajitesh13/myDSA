#include <bits/stdc++.h>
using namespace std;

int store;
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            store = d;
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "YES\n";
    } else {
        cout << store << "\n";
        cout << "NO\n";
    }
    
    return 0;
}
