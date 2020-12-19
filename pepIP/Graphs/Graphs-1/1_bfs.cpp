// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

// min-heap
class comp{
public:
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

// sort pair
bool comp1(pair<int,int> a, pair<int,int> b) {
    return(a.second < b.second);
}

vector<int> bfs(vector<vector<int>>& v, int source) {
    queue<int> q;
    vector<bool> visited(v.size()+1, false);
    vector<int> res;
    q.push(source);
    visited[source] = true;
    res.pb(source);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int a: v[top]) {
            if (!visited[a]) {
                q.push(a);
                res.pb(a);
                visited[a] = true;
            }
        }
    }
    return res;
}

void solve() {
    int t  = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> v(n+1);
        for (int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        int source;
        cin >> source;
        vector<int> res = bfs(v,source);
        for (int i=0; i<res.size(); i++) {
            cout << res[i] << ' ';
        }
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
