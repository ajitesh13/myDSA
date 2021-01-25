#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> node_rank;

int node_find(int x) {
    if (x == parent[x]) {
        return x;
    }
    int temp = node_find(parent[x]);
    parent[x] = temp;
    return temp;
}

void node_union(int x, int y) {
    int px = node_find(x);
    int py = node_find(y);
    if (px != py) {
        if (node_rank[px] > node_rank[py]) {
            parent[py] = px;
        } else if (node_rank[px] < node_rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            node_rank[py]++;
        }
    }
}

int kruskal(vector<tuple<int,int,int>> edge) {
    int res = 0;
    for (int i=0; i<edge.size(); i++) {
        if (node_find(get<1>(edge[i])) != node_find(get<2>(edge[i]))) {
            node_union(get<1>(edge[i]), get<2>(edge[i]));
            res += get<0>(edge[i]);
        }
    }
    return res;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    vector<tuple<int,int,int>> edge;
    for (int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge.push_back({z, x, y});
    }
    node_rank.assign(edge.size(), 1);
    parent.assign(edge.size(), 0);
    for (int i=0; i<edge.size(); i++) {
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());
    cout << kruskal(edge) << '\n';
    
    return 0;
}
