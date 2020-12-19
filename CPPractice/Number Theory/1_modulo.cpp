#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // find the product of all the elements of an array where v[i] = 10^18; 
    ll a = 1000000000000000000;
    vector<ll> v = {a, a, a, a, a, a};
    int m = 1000000007;
    ll ans = 1;
    for (int i=0; i<v.size(); i++) {
        ans = ((ans%m)*(v[i]%m))%m;
        cout << ans << ' ';
    } cout << '\n';
    cout << ans << '\n';
    
    return 0;
}
