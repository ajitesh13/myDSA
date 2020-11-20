// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int maxval = 0;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            maxval = max(maxval, v[i]);
        }
        int cnt = 0, ansindex;
        for (int i=0; i<n; i++) {
            if (v[i] == maxval) {
                cnt++;
                ansindex = i;
            }
        }
        if (cnt == n) { // fine
            cout << -1 << '\n';
        } else if (cnt == 1) { // fine
            cout << ansindex+1 << '\n';
        } else {
            int res;
            int cntr = 0;
            vector<int> maxar;
            for (int i=0; i<n; i++) {
                if (v[i] == maxval) {
                    maxar.pb(i);
                }
            }

            for (int i=1; i<cnt; i++) {
                if (maxar[i] - maxar[i-1] > 1) {
                    res = maxar[i]+1;
                    cntr++;
                    break;
                } 
            }
            if (cntr == 0) {
                for (int i=0; i<n; i++) {
                    if (i != 0 && v[i] == maxval && v[i-1] != maxval) {
                        res = i+1; 
                    }
                    if (i != n-1 && v[i] == maxval && v[i+1] != maxval) {
                        res = i+1;
                    }
                }
            }
            cout << res << '\n';
        }

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
