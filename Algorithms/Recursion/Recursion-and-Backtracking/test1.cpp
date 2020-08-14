#include <bits/stdc++.h>
using namespace std;
const int MAX = 10e5;


int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> adj(MAX);
        vector<bool> check(MAX, false);
        vector<int> res(MAX, -1);
        int n;
        cin >> n;
        int x, y;
        for (int i=0; i<(n-1); i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            cin >> p[i];
        }
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        int s = 1;
        queue<int> q;
        q.push(s);
        check[s] = true;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            b[top-1] = b[top-1] - min(b[top-1], a[top-1]);
            if (b[top-1] == 0) res[top] = top;
            for (int i: adj[top]) {
                if (!check[i]) {
                    q.push(i);
                    check[i] = true;
                    b[i-1] = b[i-1] - min(b[i-1], a[top-1]);
                    if (b[i-1] == 0) res[i-1] = top;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}