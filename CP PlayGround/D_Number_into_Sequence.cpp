    // g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
    #include <bits/stdc++.h>
    #define ll long long int
    #define pb push_back
    #define mp make_pair
    #define mt make_tuple
    #define pp pop_back
    using namespace std;
     
    double tick() {
        static clock_t oldt, newt = clock();
        double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
        oldt = newt;
        return diff;
    }
     
    // min-heap
    // class comp{
    // public:
    //	bool operator() (int& a, int& b) {
    //		return a > b;
    //	}
    // };
     
    // sort pair
    // bool comp1(pair<int,int> a, pair<int,int> b) {
    //     if (a.first > b.first) {
    //         return(a > b);
    //     } else if (a.first == b.first) {
    //         if (a.second > b.second) {
    //             return(b > a);
    //         }
    //     } else {
    //         return(b > a);
    //     }
    // }
     
    void solve() {
        int t;
        cin >> t;
        // int google_contest_count = 0;
        while(t--) {
            ll n;
            cin >> n;
     
            vector<pair<ll,ll>> v;
            
            for (ll i=2; i*i<=n; i++) {
                ll cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n = n/i;
                }
                if (cnt > 0) {
                    v.pb({cnt, i});
                }
            }
            if (n > 1) {
                v.pb({1, n});
            }
            sort(v.rbegin(), v.rend());
            ll num=1;
            for (ll i=1; i<v.size(); i++) {
                for (int j=1; j<=v[i].first; j++) {
                    num *= v[i].second;
                }
            }
            num *= v[0].second;
            cout << v[0].first << '\n';
            for (ll i=1; i<=v[0].first-1; i++) {
                cout << v[0].second << ' ';
            }
            cout << num << '\n';
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
        
        #ifndef ONLINE_JUDGE
            cerr << "\n**ET : " << tick() << "**\n";
        #endif
        
        return 0;
    }