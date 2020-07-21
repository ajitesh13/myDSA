// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    int a, b;
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }
    int s;
    cin >> s;
    queue<int> q;
    vector<bool> used(n);
    int d[n];
    d[s-1] = 0;
    q.push(s);
    used[s-1] = true;
    cout << s << " ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto it=adj[v-1].begin(); it!=adj[v-1].end(); it++) {
            if (!used[*it-1]) {
                used[*it-1] = true;
                q.push(*it);
                d[*it-1] = 1 + d[v-1];
                cout << *it << " ";
            }
        }
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << (i+1) << ": " << d[i] << endl;
    }
    cout << endl;
    
    return 0;
}
