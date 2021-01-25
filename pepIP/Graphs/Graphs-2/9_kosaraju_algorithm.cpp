#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;
int res =  0;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ]) {
             dfs1 (g[v][i]);
        }
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[gr[v][i]]) {
            dfs2 (gr[v][i]);
        }
}

int main() {


    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    int n, e;
    cin >> n >> e;
    g.assign(n+1, vector<int> ());
    gr.assign(n+1, vector<int> ());
    for (int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign (n+1, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n+1, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            res++;
            component.clear();
        }
    }
    cout << res-1 << '\n'; // one based indexing so, res - 1 
}
