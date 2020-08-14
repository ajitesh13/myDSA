// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;
const int MAX = 10e5;

void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, vector<int>& a, vector<int>& b, vector<int>& res) {
    visited[v] = true;
    b[v] = b[v] - min(b[v], a[v]);
    if (b[v] == 0) res[v] = v;
    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs(adj, u, visited, a, b, res);
            b[u] = b[u] - min(b[u], a[v]);
            if (b[u] == 0) res[u] = v;
        }
    }
    return;
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n;
        e = n - 1;
        int x, y;
        vector<vector<int>> adj(MAX);
        for (int i=0; i<e; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> p(MAX);
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        vector<int> a(n);
        for (int i=0; i<=n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        vector<bool> visited(n);
        vector<int> res(n);
        int s = 1;
        dfs(adj, 1, visited, a, b, res);
        for (int i=1; i<=n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
