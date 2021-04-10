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
#define int long long int
using namespace std;


vector<vector<int>> prefixsum2d(vector<vector<int>>& v) {
    int m = v[0].size();
    int n = v.size();
    vector<vector<int>> res(n, vector<int> (m, 0));
    res[0][0] = v[0][0];
    for (int i=1; i<n; i++) {
        res[i][0] = v[i][0] + res[i-1][0];
    }
    for (int j=1; j<m; j++) {
        res[0][j] = v[0][j] + res[0][j-1];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + v[i][j];
        }
    }
    return res;
}

void virya() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        // Question Link: https://www.codechef.com/COW42020/problems/COW3E/
        int n, m, u, q;
        cin >> n >> m >> u >> q;
        vector<vector<int>> v(n, vector<int> (m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> p(n, vector<int> (m, 0));
        while (u--) {
            int w, r1, c1, r2, c2;
            cin >> w >> r1 >> c1 >> r2 >> c2;
            p[r1][c1] += w;
            if (r2+1 <= n-1) {
                p[r2+1][c1] += -w;
            } 
            if (c2+1 <= m-1) {
                p[r1][c2+1] += -w;
            }
            if (r2+1 <= n-1 && c2+1 <= m-1) {
                p[r2+1][c2+1] += w;
            }
        }
        // printvvec(p);
        vector<vector<int>> res = prefixsum2d(p);
        // printvvec(res);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                res[i][j] += v[i][j];
            }
        }
        res = prefixsum2d(res);
        // printvvec(res);
        while (q--) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            if (r1 == 0 && c1 == 0) {
                cout << res[r2][c2] << "\n";
            } else if (r1 == 0) {
                cout << res[r2][c2] - res[r2][c1-1] << "\n";
            } else if (c1 == 0) {
                cout << res[r2][c2] - res[r1-1][c2] << "\n";
            } else {
                cout << res[r2][c2] - res[r2][c1-1] - res[r1-1][c2] + res[r1-1][c1-1] << "\n";
            }
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
    
    virya();
    
    return 0;
}
