#include <bits/stdc++.h>
#define int long long int
using namespace std;

int prims(vector<vector<pair<int,int>>>& adj, int source) {
    int n = adj.size();
    priority_queue<pair<int,int>> q;
    int mincost = 0;
    vector<bool> visit(n, false);
    q.push({0, source});
    while (!q.empty()) {
        pair<int,int> p = q.top();
        int a = q.top().second;
        q.pop();
        if (!visit[a]) {
            mincost += (-p.first);
            visit[a] = true;
            for (auto u: adj[a]) {
                int b = u.first, w = u.second;
                q.push({-w, b});
            }
        }
    }
    return mincost;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    int source = 1;
    cout << prims(adj, source) << '\n';
    
    return 0;
}
