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
    stack<int> st;
    vector<bool> visited(n);
    int s = 1;
    st.push(s);
    visited[s-1] = true;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (int w: adj[v - 1]) {
            if (!visited[w-1]) {
                st.push(w);
                cout << w << " ";
                visited[w-1] = true;
            }
        }
    }
    
    return 0;
}
