#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& adj) {
    vector<vector<int>> radj(adj.size());
    for (int i=1; i<adj.size(); i++) {
        for (int j=0; j<adj[i].size(); j++) {
            radj[adj[i][j]].push_back(i);
        }
    }
    return radj;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<vector<int>> radj = transpose(adj);
    for (int i=0; i<radj.size(); i++) {
        cout << i << ": ";
        for (int j=0; j<radj[i].size(); j++) {
            cout << radj[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
