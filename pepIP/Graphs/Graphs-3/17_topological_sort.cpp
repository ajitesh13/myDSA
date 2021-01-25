// write code of topo sort of graph with cycle

#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
vector<bool> visit;
vector<vector<int>> adj;

void dfs(int s) {
    if (!visit[s]) {
        visit[s] = true;
        for (int i: adj[s]) {
            
            dfs(i);
        }
        dq.push_front(s);   
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    adj.assign(n+1, vector<int> ());
    visit.assign(n+1, false);
    for (int i=1; i<=e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i=0; i<n; i++) {
        if (!visit[i]) dfs(i);
    }
    for (int i=0; i<dq.size(); i++) {
        cout << dq[i] << ' ';
    }
    cout << endl;
    
    
    return 0;
}
