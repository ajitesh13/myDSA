#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> toLeaf;
void dfs(int s, int e) {
    int maxleaflength = INT32_MIN;
    for (auto i: adj[s]) {
        if (i != e) dfs(i,s);
        maxleaflength = max(maxleaflength, toLeaf[i]);
    }
    if (adj[s].size() != 1) toLeaf[s] = maxleaflength + 1;
}

// implement this function, what does it do ? it will calculate the diameter by calculating for each node x 
// the max of (toLeaf(a)+toLeaf(b)+2) where a and b are children of x the max of all sum (toLeaf(a)+toLeaf(b)+2) is the diameter 
void calculate_diameter() {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    toLeaf.assign(n+1, 0);
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    for (int i=0; i<toLeaf.size(); i++) {
        cout << i << ": " << toLeaf[i] << "\n";
    }
    
    return 0;
}
