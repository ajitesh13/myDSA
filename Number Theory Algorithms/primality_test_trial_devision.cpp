#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << isPrime(5) << '\n';
    
    return 0;
}
