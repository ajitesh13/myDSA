#include <bits/stdc++.h>
using namespace std;

int n, e, cycle_start = -1, cycle_end = -1;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;

bool dfs(int s, int pre) {
    vis[s] = true;
    for (auto i: adj[s]) {
        if (i != pre) {
            if (!vis[i]) {
                parent[i] = s;
                if (dfs(i, s)) 
                    return true;
            } else {
                cycle_end = s;
                cycle_start = i;
                return true;
            }
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    adj.resize(n+1);
    parent.assign(n+1, -1);
    vis.assign(n+1, false);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i] and dfs(i, 0)) 
            break;
    }
    if (cycle_start == -1) {
       cout << "Acyclic\n";
    } else {
        vector<int> res;
        for (int i=cycle_end; i!=cycle_start; i = parent[i]) {
            res.push_back(i);
        }
        res.push_back(cycle_start);
        reverse(res.begin(),res.end());
        for (int i=0; i<res.size(); i++) {
            cout << res[i] << " ";
        }
    }
    
    return 0;
}
