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
//#define int long long int
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
vector<double> v;
double res = 0.0;
void go(string s, int th, int tl, double preans) {
    // cout << s << " " << preans << "\n";
    res += preans;
    if (th - 1 > tl + 1) {
        for (int i=0; i<s.size(); i++) {
            string s1 = s;
            double preans1 = preans;
            if (s[i] != 'T') {
                s1[i] = 'T';
                preans1 /= v[i];
                go(s1,th-1,tl+1,preans1*(1-v[i]));
            }
        }
    }
}
void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        cin >> n;
        v.resize(n);
        double preans = 1.0;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            preans *= v[i];
        }
        string s;
        for (int i=0; i<n; i++) {
            s.pb('H');
        }
        go(s, n, 0, preans);
        cout << res << "\n";
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
    
    best();
    
    return 0;
}
