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

int mod = 1000000007;
void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for (int i=0; i<n; i++) {
            vector<int> te;
            for (int j=0; j<m; j++) {
                char ch;
                cin >> ch;
                if (ch == '.') te.pb(0);
                else te.pb(1);
            }
            v.pb(te);
        }
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        for (int i=1; i<n; i++) {
            if (v[i][0] != 1) {
                if (dp[i-1][0] == 1) dp[i][0] = 1;
            }
        }
        for (int j=1; j<m; j++) {
            if (v[0][j] != 1) {
                if (dp[0][j-1] == 1) dp[0][j] = 1;
            }
        }
        // printvvec(dp);
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (v[i][j] != 1) {
                    int t1 = 0, t2 = 0;
                    if (v[i-1][j] != 1) t1 = dp[i-1][j];
                    if (v[i][j-1] != 1) t2 = dp[i][j-1];
                    dp[i][j] = (t1%mod + t2%mod)%mod;
                }
            }
        }
        // printvvec(dp);
        cout << dp[n-1][m-1] << "\n";
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
