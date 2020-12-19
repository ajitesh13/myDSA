// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5+23;
int a[N], b[N];
vector<vector<pair<int,int>>> cycles;
vector<pair<int,int>> swaps;
vector<pair<pair<int,int>,int>> sol;

void solve() {
    int n, k, parity = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    vector<vector<pair<int,int>>> oddcycles;
    for (int i=1; i<=n; i++) {
        vector<pair<int,int>> v;
        while (a[i] != i) {
            v.push_back(make_pair(i, a[i]));
            parity++;
            swap(a[i], a[a[i]]);
        }
        if (v.size()) {
            if (v.size() % 2 == 0) {
                cycles.push_back(v);
            } else {
                oddcycles.push_back(v);
            }
        }
    }
    for (int i=0; i<oddcycles.size(); i++) {
        cycles.push_back(oddcycles[i]);
    }
    if (parity % 2 == 1) {
        cout << -1 << "\n";
        return;
    }
    if (n == 3) {
        if (b[1] == 1) {
            cout << "0\n";
        } else if (b[1] == 2) {
            cout << "1\n";
            cout << "1 2 3\n";
        } else {
            cout << "1 \n";
            cout << "1 3 2\n";
        }
        return;
    }
    for (auto f: cycles) {
        for (auto g: f) {
            if (g.first > g.second) {
                swap(g.first, g.second);
            }
            swaps.push_back(g);
        }
    }
    for (int x=0; x < swaps.size(); x += 2) {
        pair<int,int> f = swap[x], g = swaps[x+1];
        
    }

}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int tc = 1;
    int t;
    cin >> t;
    while (t--) {
        solve();
        
        // cout << "Case #" << tc << ": " <<<< "\n"; tc++;
    }
    
    return 0;
}