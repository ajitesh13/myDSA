#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, 
        int& timer, vector<vector<int>>& adj, set<int>& isArticulation) {
    
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it: adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            child++;
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] and parent != -1) {
                isArticulation.insert(node);
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 and child > 1) {
        isArticulation.insert(node);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0) break;
        vector<vector<int>> adj(n+1);
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n+1, -1);
        vector<int> low(n+1, -1);
        vector<int> vis(n+1, 0);
        set<int> isArticulation;
        int timer = 0;
        for (int i=1; i<=n; i++) {
            if (!vis[i]) {
                dfs(1,-1,vis,tin,low,timer,adj,isArticulation);
            }
        }
        cout << isArticulation.size() << "\n";
    }
    
    return 0;
}
