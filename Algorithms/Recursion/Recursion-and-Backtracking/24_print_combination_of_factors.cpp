// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pp pop_back
using namespace std;
const int MAX = 10e6;
vector<vector<int>> res;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void store(int first, int ep, int n, vector<int> cp) {
    if (first >= n || ep > n) {
        return;
    }
    if (ep == n) {
        res.pb(cp);
        return;
    }
    for (int i=first; i<n; i++) {
        if (i*ep > n) {
            break;
        }
        if (n%i == 0) {
            cp.pb(i);
            store(i, i*ep, n, cp);
            cp.pp();
        }
    }
}

void gen(int n) {
    vector<int> cp;
    store(2,1,n,cp);
}

void solve() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        gen(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<res[i].size(); j++) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    return 0;
}
