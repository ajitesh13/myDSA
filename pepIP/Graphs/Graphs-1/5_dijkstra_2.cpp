#include <bits/stdc++.h>
#define int long long int
using namespace std;

// cses shortest distance - 1
// one direction only 
vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int source) {
    int n = adj.size();
    priority_queue<pair<int,int>> q;
    vector<int> distance(n, INT64_MAX);
    vector<bool> visit(n, false);
    distance[source] = 0;
    q.push({0, source});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (!visit[a]) {
            visit[a] = true;
            for (auto u: adj[a]) {
                int b = u.first, w = u.second;
                distance[b] = min(distance[b], distance[a]+w);
                q.push({-distance[b], b});
            }
        }
    }
    return distance;
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
    int source = 1, target = n;
    // cin >> source >> target;
    vector<int> res = dijkstra(adj, source);
    for (int i=1; i<=n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}