// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;
const int MAX = 10e5;

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n;
        e = n - 1;
        int x, y;
        vector<vector<int>> adj(MAX);
        for (int i=0; i<e; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> p(n+1);
        vector<int> a(n+1);
        vector<int> b(n+1);
        vector<int> res(n+1, -1);
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        stack<int> st;
        vector<bool> check(n, false);
        int s = 1;
        st.push(s);
        check[s] = true;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            b[top] = b[top] - min(b[top], a[top]);
            if (b[top] == 0) res[top] = top;
            for (int i: adj[top]) {
                if (!check[i]) {
                    st.push(i);
                    check[i] = true;
                    b[i] = b[i] - min(b[i], a[top]);
                    if (b[i] == 0) res[i] = top;
                }
            }
        }
        for (int i=1; i<=n; i++) {
                cout << res[i] << " ";
            }
        cout << "\n";
    }
    
    return 0;
}
