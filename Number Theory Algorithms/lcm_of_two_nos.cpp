#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << lcm(6, 4) << '\n';
    
    return 0;
}
