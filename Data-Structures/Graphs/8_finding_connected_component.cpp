// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

void dfs(int v, vector<bool>& visited, vector<int> adj[]) {
    visited[v-1] = true;
    for (int u: adj[v-1]) {
        if (!visited[u-1]) {
            dfs(u, visited, adj);
        }
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    int a, b;
    vector<int> adj[n];
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }
    vector<bool> visited(n);
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }
    int cntr = 0;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i+1, visited, adj);
            cntr++;
        }
    }
    cout << cntr << endl;
    
    return 0;
}
