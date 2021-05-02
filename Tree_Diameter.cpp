#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> toLeaf;
vector<int> maxLength;
void dfs(int s, int e) {
    int maxleaflength = INT32_MIN;
    for (auto i: adj[s]) {
        if (i != e) dfs(i,s);
        maxleaflength = max(maxleaflength, toLeaf[i]);
    }
    if (adj[s].size() != 1) toLeaf[s] = maxleaflength + 1;
}

void dfs1(int s, int e) {
    int mx1 = INT32_MIN, mx2 = INT32_MIN;
    if (adj[s].size() > 1) {
        for (auto j: adj[s]) {
            if (j != e) {
                if (toLeaf[j] > mx2) {
                    mx1 = mx2;
                    mx2 = toLeaf[j];
                } else if (toLeaf[j] > mx1) {
                    mx1 = toLeaf[j];
                }
            }
        }
        maxLength[s] = mx1 + mx2 + 2;
    }
    for (auto i: adj[s]) {
        if (i != e) dfs1(i,s);
    }
}


int calculate_diameter() {
    int mx = INT32_MIN;
    for (int i=0; i<maxLength.size(); i++) {
        mx = max(maxLength[i], mx);
    }
    return mx;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n;
    adj.resize(n+1);
    toLeaf.assign(n+1, 0);
    maxLength.assign(n+1, 0);
    e = n-1;
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (n == 1) {
        cout << 0 << "\n";
    } else if (n == 2) {
        cout << 1 << "\n";
    } else {
        int root;
        for (int i=0; i<adj.size(); i++) {
            if (adj[i].size() > 1) {
                root = i;
                break;
            }
        }
        dfs(root,0);
        dfs1(root,0);
        cout << calculate_diameter() << "\n";
    }
    
    return 0;
}
