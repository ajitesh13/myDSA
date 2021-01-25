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
    
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    parent.assign(2*n, 0);
    for (int i=0; i<parent.size(); i++) {
        parent[i] = i;
    }
    node_rank.assign(2*n, 1);
    vector<int> res;
    for (int i=0; i<n; i++) {
        if (node_find(edges[i][0]) != node_find(edges[i][1])) {
            node_union(edges[i][0], edges[i][1]);
        } else {
            res.clear();
            res.push_back(edges[i][0]);
            res.push_back(edges[i][1]);
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> res = findRedundantConnection(edges);
    
    return 0;
}
