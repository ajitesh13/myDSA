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

// gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    int temp = gcd(b, a%b);
    return temp;
}

void virya() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n+1, 0);
        vector<pair<int,int>> vp;
        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            while (x != y) {
                vp.pb({x, y});
                x++;
            }
            vp.pb({x,y});
        }
        for (int i=0; i<vp.size(); i++) {
            v[vp[i].first] += 1;
            if (vp[i].second+1 <= n) {
                v[vp[i].second+1] += -1;
            }
        }
        for (int i=2; i<=n; i++) {
            v[i] += v[i-1];
        }
        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            cout << v[x] << "\n";
        }
        // printvecp(vp);
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
