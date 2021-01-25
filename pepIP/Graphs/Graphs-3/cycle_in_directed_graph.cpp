#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visit;
unordered_set<int> st;
int cycle = -1;

void dfs(int s) {
    if (st.find(s) == st.end()) {
        if (!visit[s]) {
            visit[s] = true;
            st.insert(s);
            for (int i: adj[s]) {
                dfs(i);
            }
        }
    } else {
        cycle = 0;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    visit.assign(n+1, false);
    adj.assign(n+1, vector<int> ());
    for (int i=0; i<n; i++) {
        if (!visit[i] ) {
            dfs(i);
        }
    }
    if (cycle == 0) {
        cout << true << '\n';
    } else {
        cout << false << '\n';
    }


    
    return 0;
}
