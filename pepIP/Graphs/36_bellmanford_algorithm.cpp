#include <bits/stdc++.h>
using namespace std;
int n, e, neg_cycle = 0;

vector<int> bellmanford(int source, vector<tuple<int,int,int>> edges) {
    vector<int> distance(n+1, INT32_MAX);
    distance[source] = 0;
    for (int i=1; i<=n; i++) {
        for (auto e: edges) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if (distance[u] == INT32_MAX) {
                continue;
            } else {
                if (distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    if (i == n) neg_cycle = 1;
                }
            }
        } 
    }
    return distance;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    vector<tuple<int,int,int>> edges;
    for (int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    int source;
    cin >> source;
    vector<int> distance = bellmanford(source, edges);
    if (neg_cycle == 1) cout << "Negative Cycle\n";
    else {
        for (int i=1; i<distance.size(); i++) {
            cout << distance[i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
