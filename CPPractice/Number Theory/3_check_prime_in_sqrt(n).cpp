#include <bits/stdc++.h>
using namespace std;

void checkprime(int n) {
    int count = 0;
    for (int i=1; i*i <= n; ++i) {
        if (n % i == 0) {
            if (i*i == n) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    if (count == 2) {
        cout << n << " is prime" << '\n';
    } else {
        cout << n << " is not prime" << '\n';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    checkprime(9);
    
    return 0;
}
