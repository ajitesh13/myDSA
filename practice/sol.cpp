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

    int N = 1;
    vector<vector<int>> trust = {{1, 2}};
    
    int e = trust.size();
        vector<vector<int>> adj(N);
        unordered_set<int> st;
        for (auto i: trust) {
            int a = i[0];
            int b = i[1];
            adj[b-1].push_back(a);
            st.insert(a);
        }
        int j = 0, res = 0;
        for (auto i: adj) {
            if (i.size() == N-1) {
               res = j+1;
            }
            j++;
        }
        if (st.find(res) == st.end()) {
            return res;
        } else {
            return -1;
        }

    return 0;
}
