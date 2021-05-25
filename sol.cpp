#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int timer = 0;
vector<bool> vis;
vector<int> ins;
vector<int> low;
vector<bool> articulation_point;

void dfs(int node, int parent) {
    vis[node] = true;
    ins[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for (auto i: adj[node]) {
        if (i == parent) continue;

        if (!vis[i]) {
            dfs(i, node);
            child++;
            low[node] = min(low[node], low[i]);
            if (low[i] >= ins[node] and parent != -1) {
                articulation_point[node] = true;
            }
        } else {
            low[node] = min(low[node], ins[i]);
        }
    }
    if (parent == -1 and child > 1) articulation_point[node] = true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    vis.assign(n+1, false);
    ins.resize(n+1);
    low.resize(n+1);
    articulation_point.assign(n+1, false);
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    for (int i=1; i<=n; i++) {
        if (articulation_point[i]) cout << i << " ";
    }
    
    return 0;
}
