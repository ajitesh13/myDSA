#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cont(it,x) for (auto it=x.begin(); it!=x.end(); it++){cout << *it << ' ';} cout << '\n';
#define contp(it,x) for (auto it=x.begin(); it!=x.end(); it++){cout << it->first << " - " << it->second << '\n';}
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printp(x) cout<<x.first<<' '<< x.second<<'\n';
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define printadj(n,x) for (int i=0; i<n; i++) {cout<<i<<": ";for(int j=0;j<x[i].size();j++){cout<<adj[i][j]<<' ';}cout<<'\n';}
#define int long long int
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define invec(v, n) for(int i=0;i<v.size();i++)cin>>v[i];

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

int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> low;
vector<int> ins;
int timer = 1;
vector<pair<int,int>> res;
vector<int> par;

void dfs(int node, int parent) {
    vis[node] = true;
    low[node] = timer;
    ins[node] = timer;
    timer++;
    for (auto i: adj[node]) {
        if (i == parent) continue;
        if (!vis[i]) {
            dfs(i,node);
            par[i] = node;
            low[node] = min(low[node], low[i]);
            if (low[i] > ins[node]) {
                if (i > node) {
                    res.pb({node, i});
                } else res.pb({i,node});
            }
        } else if (par[node] != i) {
            low[node] = min(low[node], ins[i]);
        }
    }
}
void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        cin >> n;
        adj.resize(n);
        vis.assign(n, false);
        low.resize(n);
        ins.resize(n);
        par.assign(n, -1);
        for (int i=0; i<n; i++) {
            int x;
            string y;
            cin >> x >> y;
            int m = y[1]-'0';
            for (int j=0; j<m; j++) {
                int z;
                cin >> z;
                adj[z].pb(x);
            }
        }
        
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }
        // printadj(adj.size(), adj);
        sort(all(res));
        cout << res.size() << " critical links\n";
        contp(z,res);
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
    #endif
    
    best();
    
    return 0;
}
