#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<bool> articulation_point;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;  
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                articulation_point[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1) {
        articulation_point[v] = true;
    }
        
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    articulation_point.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e;
    cin >> n >> e;
    adj.assign(n+1, vector<int> ());
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_cutpoints();
    for (int i=0; i<n; i++) {
        if (articulation_point[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
    
    return 0;
}
