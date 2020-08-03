// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
#define MAX 10e5
//#define MAX 10e4
using namespace std;
vector<vector<int>> adj(MAX);

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, e;
    cin >> n >> e;
    int a, b;
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> st;
    st.push(0);
    vector<bool> check(MAX);
    check[0] = true;
    while (!st.empty()) {
        int v = st.top();
        cout << v << " ";
        st.pop();
        for (int i=(adj[v].size()-1); i>=0; i--) {
            int l = adj[v][i];
            if (!check[l]) {
                check[l] = true;
                st.push(l);
                // cout << i << " ";
            }
        }
    }
    
    return 0;
}
