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
    int a, b;
    vector<int> adj[n];
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }
    int s;
    cin >> s;
    queue<int> q;
    vector<bool> used(n);
    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: adj[v-1]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                cout << u << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
