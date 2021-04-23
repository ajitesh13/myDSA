#include <bits/stdc++.h>
using namespace std;

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
#define int long long int 

// Problem Link: https://www.codechef.com/SPYB21B/problems/GOTHAM

void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        set<pair<int,int>> st;
        for (int i=0; i<n; i++) {
            st.insert({i+1, v[i]});
        }
        int q;
        cin >> q;
        while (q--) {
            int x, k, res = 0;
            cin >> x >> k;
            auto it = st.lower_bound({x,0});
            while (it != st.end() && k > 0) {
                if (it->second > k) {
                    res += (k*(it->first-x));
                    st.insert({it->first, it->second - k});
                    st.erase(it);
                    k = 0;
                } else { 
                    res += (it->second*(it->first - x));
                    k = k - it->second;
                    auto itr = it;
                    it++;
                    st.erase(itr);
                }
            }
            cout << res << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        // freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
    #endif
    
    best();
    
    return 0;
}
