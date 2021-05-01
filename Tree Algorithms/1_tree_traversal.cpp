#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;

void dfs(int s, int e) {
    cout << s << " ";
    for (auto i: adj[s]) {
        if (i != e) dfs(i, s);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); 
        adj[y].push_back(x);
    }
    dfs(1, 0); // if starting dfs from node 1
    // dfs(0, -1); // if starting dfs from node 0
    
    return 0;
}
