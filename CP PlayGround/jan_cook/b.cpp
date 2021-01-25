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
vector<int> res;

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

unordered_set<int> sieve(int n) {
    unordered_set<int> st;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<=n; i++) {
        if (is_prime[i] && (long long)i*i <= n) {
            for (int j=i*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (is_prime[i] == true) {
            res.pb(i);
            st.insert(i);
        }
    }
    return st;
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        res.clear();
        unordered_set<int> st = sieve(n);
        int ans = 0;
        for (int i=0; i<res.size(); i++) {
            for (int j=i+1; j<res.size(); j++) {
                if (st.find(res[i] + res[j]) != st.end()) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
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
    
    return 0;
}
