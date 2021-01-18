#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// operate in 1 based indexing
vector<ll> fenwick;
vector<ll> v;

int sum(ll i) {
    ll sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= (i & -i);
    }
    return sum;
}

void update(ll i, ll delta) {
    while (i <= v.size()) {
        fenwick[i] += delta;
        i += (i & -i);
    }
}

int rangesum(ll l, ll r) {
    return sum(r)-sum(l-1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out1", "w", stdout);
    #endif

    int n = 16;
    v = {0,2,1,-3,5,4,8,2,-2,3,6,2,1,-1,2,-2,1};
    fenwick.assign(n+1, 0);
    for (int i=1; i<=n; i++) {
        update(i, v[i]); 
    }
    cout << rangesum(3,5) << '\n';

    return 0;
}
