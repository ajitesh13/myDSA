#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define printvec(x) for(int _=0;_<x.size();_++){cerr<<x[_]<<' ';}cerr<<'\n';
#define printvvec(x) for(int _=0;_<x.size();_++){for(int __=0;__<x[_].size(); __++){cerr<<x[_][__]<<' ';}cerr<<'\n';}
#define printmap(x) for(auto _=x.begin();_!=x.end();_++){cerr<<_->first<<' '<<_->second<<'\n';}
#define printset(x) for(auto _=x.begin();_!=x.end();_++){cerr<<*_<<' ';}cerr<<'\n';
#define printvecp(x) for(int _=0;_<x.size();_++){cerr<<x[_].first<<' '<<x[_].second<<'\n';}
#define printp(x) cerr<<x.first<<' '<< x.second<<'\n';
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

// gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    int temp = gcd(b, a%b);
    return temp;
}

int cal(int m, int start, int dest) {
    int res = 0;
    while (start != dest) {
        // cout << start << " " << dest << "\n";
        start++;
        if (start == m+1) {
            start = 1;
        }
        res++;
    }
    // cout << res << "\n";
    return res;
}

void virya() {
    int __=1;
    // cin >> __;
    // int google_contest_count = 0;
    while(__--) {
        int m, n;
        cin >> m >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        int res = 0;
        res += cal(m, 1, v[0]);
        for (int i=0; i<n-1; i++) {
            res += cal(m, v[i], v[i+1]);
        }
        cout << res << "\n";
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
    #endif
    
    virya();
    
    return 0;
}
