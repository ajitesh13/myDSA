#include <bits/stdc++.h>
#define printvec(x) for(int i=0; i<x.size(); i++) {cout << x[i] << ' ';}cout << '\n';
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    parent.assign(n, 0);
    node_rank.assign(n, 1);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    node_union(0, 1);
    node_union(0, 2);
    node_union(4, 5);
    printvec(parent);
    printvec(node_rank);
    return 0;
}
