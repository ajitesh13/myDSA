#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

void dfs(int s, int e) {
    dp[s] = 1;
    for (auto i: adj[s]) {
        if (i != e) {
            dfs(i,s);
            dp[s] += dp[i];
        } 
    }
} 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    dp.assign(n+1, 0);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    for (int i=0; i<dp.size(); i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
