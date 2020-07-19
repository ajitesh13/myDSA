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
    cin >> n;
    cin >> e;
    int a, b;
    vector<int> adj[n];
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b);
    }
    for (int i=0; i<n; i++) {
        cout << (i+1) << ": ";
        for (auto it=adj[i].begin(); it!=adj[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    
    return 0;
}
