#include <bits/stdc++.h>
using namespace std;

int n, e, x;
vector<tuple<int,int,int>> edge;
vector<int> dist;
vector<int> parent;

void bellmanford() {
    for (int i=1; i<=n; i++) {
        x = -1;
        for (auto e: edge) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    dist.assign(n+1, 0);
    parent.assign(n+1, -1);
    for (int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge.push_back({x,y,z});
    }
    bellmanford();
    if (x == -1) {
        cout << "No Negative Cycle\n";
    } else {
        cout << "Yes Negative Cycle\n";
        for (int i=1; i<=n; i++) {
            x = parent[x];
        }
        vector<int> res;
        for (int i=x;; i = parent[i]) {
            res.push_back(i);
            if (i == x and res.size() > 1) {
                break;
            }
        }
        reverse(res.begin(), res.end());
        for (int i=0; i<res.size(); i++) cout << res[i] << " ";
    }
    
    return 0;
}
