#include <bits/stdc++.h>
using namespace std;
int n, e;

vector<int> bellmanford(int source, vector<tuple<int,int,int>> edges) {
    vector<int> distance(n, INT32_MAX);
    distance[source] = 0;
    for (int i=1; i<=(n-1); i++) {
        for (auto e: edges) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if (distance[u] == INT32_MAX) {
                continue;
            } else {
                distance[v] = min(distance[v], distance[u]+w);
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
    for (int i=0; i<distance.size(); i++) {
        cout << distance[i] << ' ';
    }
    cout << endl;

    
    return 0;
}
