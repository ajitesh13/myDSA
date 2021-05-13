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
#define contp(it,x) for (auto it=x.begin(); it!=x.end(); it++){cout << it->first << ' ' << it->second << '\n';}
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printp(x) cout<<x.first<<' '<< x.second<<'\n';
#define fo(i,start,end) int i=start;i<end;i++
#define foi(i,start,end) int i=start;i<=end;i++
#define fot(it, x) auto it=x.begin();it!=x.end();it++
#define printadj(n,x) for (int i=0; i<n; i++) {cout<<i<<": ";for(int j=0;j<x[i].size();j++){cout<<adj[i][j]<<' ';}cout<<'\n';}
#define int long long int

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

// gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    int temp = gcd(b, a%b);
    return temp;
}

int n, e, x;
vector<tuple<int,int,int>> edge;
vector<int> dist;
vector<int> parent;
void bellmanford() {
    for (int i=1; i<=n; i++) {
        x = -1;
        for (auto e: edge) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }
}
void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        cin >> n >> e;
        dist.assign(n+1, 0);
        parent.assign(n+1, -1);
        for (int i=0; i<e; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edge.pb({x,y,z});
        }
        bellmanford();
        if (x == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                x = parent[x];
            }
            vector<int> res;
            for (int i=x;; i = parent[i]) {
                res.pb(i);
                if (i == x and res.size() > 1) {
                    break;
                }
            }
            reverse(all(res));
            cont(z,res);
        }
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
