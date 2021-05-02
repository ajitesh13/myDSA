#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int distance1 = 0, distance2 = 0, farthest1, farthest2;

// finding farthest1 i.e. one end of the farthest possible distance
void dfs1(int s, int e, int distance) {
    if (distance > distance1) {
        distance1 = distance;
        farthest1 = s;
    }
    for (auto i: adj[s]) {
        if (i != e) dfs1(i, s, distance + 1);
    }
}

// finding farthest2 i.e. anther end of the farthest possible distance 
void dfs2(int s, int e, int distance) {
    if (distance > distance2) {
        distance2 = distance;
        farthest2 = s;
    }
    for (auto i: adj[s]) {
        if (i != e) dfs2(i,s,distance+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n;
    e = n-1;
    adj.resize(n+1);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, 0, 0);
    dfs2(farthest1, 0, 0);
    cout << distance2 << "\n";
    
    return 0;
}
