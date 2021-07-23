#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> parent;
vector<int> msize;

int node_find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return node_find(parent[x]);
    }
}

void node_union(int x, int y) {
    int px = node_find(x);
    int py = node_find(y);
    if (msize[px] > msize[py]) {
        parent[py] = px;
        msize[px] += msize[py];
    } else {
        parent[px] = py;
        msize[py] += msize[px];
    } 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    parent.resize(n);
    for (int i=0; i<parent.size(); i++) {
        parent[i] = i;
    }
    msize.assign(n, 1);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        if (node_find(x) != node_find(y)) {
            node_union(x, y);
        }
    }

    for (int i=0; i<msize.size(); i++) {
        cout << msize[i] << " ";
    }
    
    return 0;
}
