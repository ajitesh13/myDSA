#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int s;
    cin >> s;
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(s);
    visited[s] = true;
    cout << s << ' ';
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int j=0; j<adj[top].size(); j++) {
            if (!visited[adj[top][j]]) {
                q.push(adj[top][j]);
                cout << adj[top][j] << ' ';
                visited[adj[top][j]] = true;
            }
        }
    }
    return 0;
}