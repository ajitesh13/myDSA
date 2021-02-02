#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define printvec(x) for(int _=0;_<x.size();_++){cout<<x[_]<<' ';}cout<<'\n';
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cout<<x[_][__]<<' ';}cout<<'\n';}
#define printmap(x) for(auto _=x.begin();_!=x.end();_++){cout<<_->f<<' '<<_->s<<'\n';}
#define printset(x) for(auto _=x.begin();_!=x.end();_++){cout<<*_<<' ';}cout<<'\n';
#define printvecp(x) for(int _=0;_<x.size();_++){cout<<x[_].f<<' '<<x[_].s<<'\n';}
#define printp(x) cout<<x.f<<' '<< x.s<<'\n';
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

int afrog(vector<int>& v, int i, vector<int>& dp) {
    if (i == 0) {
        dp[0] = 0;
        return dp[i];
    } else if (i == 1) {
        dp[i] = afrog(v, i-1, dp)+abs(v[i]-v[i-1]);
        return dp[i];
    } else {
        if (dp[i] == -1) {
            dp[i] = min(afrog(v, i-1, dp)+abs(v[i]-v[i-1]), afrog(v, i-2, dp)+abs(v[i]-v[i-2]));
            return dp[i];
        } else {
            return dp[i];
        }
        
    }
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        vector<int> dp(n+1, -1);
        int res = afrog(v, n-1, dp);
        cout << res << '\n';
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        // freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}
