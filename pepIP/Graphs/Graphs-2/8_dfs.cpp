#include <bits/stdc++.h>
using namespace std;
vector<bool> visit;
vector<vector<int>> adj;

void dfs(int s) {
    if (!visit[s]) {
        visit[s] = true;
        cout << s << '\n';
        for (int i: adj[s]) {
            dfs(i);
        }
    } 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.assign(n+1, vector<int> ());
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int source;
    cin >> source;
    visit.assign(n+1, false);
    dfs(source);
    
    return 0;
}
