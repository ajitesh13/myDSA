// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
#define MAX 10e4
//#define MAX 10e4
using namespace std;
vector<vector<int>> v(MAX);
vector<bool> check(MAX);
int path;

void dfs(int s, int d) {
    for (int i: v[s]) {
        if (i == d) {
            path++;
            continue;
        }
        if (!check[i]) {
            dfs(i, d);
        }
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        int a, b;
        for (int i=0; i<e; i++) {
            cin >> a >> b;
            v[a].push_back(b);
        }
        int source, destination;
        cin >> source >> destination;
        check[source] = true; 
        dfs(source, destination);
        cout << path << endl;
    }
    
    return 0;
}
