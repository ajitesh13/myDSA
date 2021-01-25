#include <bits/stdc++.h>
using namespace std;
vector<int> indegree(6, 0);
vector<vector<int>> adj = {{}, {}, {3}, {1}, {0,1}, {2,0}};
vector<int> res;

void kahn() {
    queue<int> q;
    for (int i=0; i<adj.size(); i++) {
        for (int j=0; j<adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }
    for (int i=0; i<indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int rem = q.front();
        q.pop();
        res.push_back(rem);
        for (int i=0; i<adj[rem].size(); i++) {
            if (indegree[adj[rem][i]]) {
                indegree[adj[rem][i]]--;
                if (indegree[adj[rem][i]] == 0) {
                    q.push(adj[rem][i]);
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    kahn();
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
    
    return 0;
}
