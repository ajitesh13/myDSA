#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return a ? gcd(b%a, a):b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << gcd(7,12) << '\n';

    
    return 0;
}
