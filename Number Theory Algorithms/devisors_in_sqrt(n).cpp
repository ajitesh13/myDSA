#include <bits/stdc++.h>
#define ll int long long
#define pb push_back
using namespace std;

vector<ll> printD(int n) {
    vector<ll> res;
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i == 0) {
            if (n/i == i) {
                res.pb(i);
            } else {
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<ll> v = printD(810);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    
    return 0;
}
