#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;
vector<int> dp;

void dfs(int s, int e) {
    dp[s] = 1;
    for (auto i: adj[s]) {
        if (i != e) dfs(i, s);
        dp[s] += dp[i];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in", "r", stdin);
    
    int n, e;
    cin >> n >> e;
    adj.assign(n+1, vector<int> ());
    dp.assign(n+1, 0);
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // only single time addition
    }
    dfs(1, 0);
    for (int i=0; i<=n; i++) cout << i << ": " << dp[i] << "\n";
    return 0;
}
