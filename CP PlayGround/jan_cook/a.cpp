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

int compare(vector<string> a, vector<string> b, int n, int m) {
    int res = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] != b[i][j]) {
                res++;
            }
        }
    }
    return res;
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        string cmp1 = "*";
        string cmp2 = ".";
        for (int i=1; i<m; i++) {
            if (i%2 != 0) {
                cmp1.push_back('.');
                cmp2.push_back('*');
            } else {
                cmp1.push_back('*');
                cmp2.push_back('.');
            }
        }
        vector<string> mat1;
        vector<string> mat2;
        for (int i=0; i<n; i++) {
            if (i%2 == 0) {
                mat1.push_back(cmp1);
                mat2.push_back(cmp2);
            } else {
                mat1.push_back(cmp2);
                mat2.push_back(cmp1);
            }
        }
        int ans1 = compare(v, mat1, n, m);
        int ans2 = compare(v, mat2, n, m);
        cout << min(ans1, ans2) << '\n';
        
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
