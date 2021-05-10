#include <bits/stdc++.h>
using namespace std;

int n, e, cycle_start = -1, cycle_end = -1;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;

bool dfs(int s) {
    color[s] = 1;
    for (auto i: adj[s]) {
        if (color[i] == 0) {
            parent[i] = s;
            if (dfs(i)) 
                return true;
        } else if (color[i] == 1) {
            cycle_start = i;
            cycle_end = s;
            return true;
        }
    }
    parent[s] = 2;
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    adj.resize(n+1);
    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i=1; i<=n; i++) {
        if (color[i] == 0 and dfs(i)) {
            break;
        }
    }
    if (cycle_start == -1) {
        cout << "DAG\n";
    } else {
        cout << "Cycle: ";
        vector<int> res;
        for (int i=cycle_end; i!=cycle_start; i = parent[i]) {
            res.push_back(i);
        } 
        res.push_back(cycle_start);
        reverse(res.begin(), res.end());
        for (int i=0; i<res.size(); i++) {
            cout << res[i] << " ";
        }
    }
    
    return 0;
}
