#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define printvec(x) for(int _=0;_<x.size();_++){cout<<x[_]<<' ';}cout<<'\n';
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printmap(x) for(auto _=x.begin();_!=x.end();_++){cout<<_->first<<' '<<_->second<<'\n';}
#define printset(x) for(auto _=x.begin();_!=x.end();_++){cout<<*_<<' ';}cout<<'\n';
#define printvecp(x) for(int _=0;_<x.size();_++){cout<<x[_].first<<' '<<x[_].second<<'\n';}
#define printp(x) cout<<x.first<<' '<< x.second<<'\n';
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define invec(v, n) for(int i=0;i<v.size();i++)cin>>v[i];
using namespace std;

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

// string to int
int string_to_int(string s) {
    stringstream a(s);
    int x;
    a >> x;
    return x;
}

int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj1;
vector<int> parent;
vector<int> node_rank;

int node_find(int x) {
    if (x == parent[x]) {
        return x;
    }
    int temp = node_find(parent[x]);
    parent[x] = temp;
    return temp;
}

void node_union(int x, int y) {
    int px = node_find(x);
    int py = node_find(y);
    if (px != py) {
        if (node_rank[px] > node_rank[py]) {
            parent[py] = px;
        } else if (node_rank[px] < node_rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            node_rank[py]++;
        }
    }
}

void solve() {
    int __ = 1;
    // cin >> __;
    // int google_contest_count = 0;
    while(__--) {
        cin >> n >> m;
        adj.assign(n+1, vector<int> ());
        adj1.assign(m+1, vector<int> ());
        parent.assign(n+1, 0);
        node_rank.assign(n+1, 1);
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            for (int j=1; j<=x; j++) {
                int y;
                cin >> y;
                adj[i].pb(y);
                adj1[y].pb(i);
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (adj[i].size() != 0) {
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << n << '\n';
        } else {
            for (int i=1; i<=n; i++) {
                parent[i] = i;
            }
            for (int i=1; i<=n; i++) {
                for (int j=0; j<adj[i].size(); j++) {
                    for (int k=0; k<adj1[adj[i][j]].size(); k++) {
                        if (node_find(i) != node_find(adj1[adj[i][j]][k])) {
                            node_union(i,adj1[adj[i][j]][k]);
                        }
                    }
                }
            }
            unordered_set<int> st;
            for (int i=1; i<=n; i++) {
                st.insert(parent[i]);
            }
            cout << st.size()-1 << '\n';
        }
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}
