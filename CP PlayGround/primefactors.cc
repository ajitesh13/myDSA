#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> fprime(ll n) {
    vector<ll> res;  
    while (n % 2 == 0) {  
        res.push_back(2);
        n = n/2;  
    }  

    for (ll i = 3; i <= sqrt(n); i = i + 2) {  
        while (n % i == 0) {   
            res.push_back(i);
            n = n/i;  
        }  
    }  
   
    if (n > 2) {
        res.push_back(n);
    }  

    return res;
}

int main() {
    ll n = 9876543210;
    vector<ll> res = fprime(n);
    for (ll i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}