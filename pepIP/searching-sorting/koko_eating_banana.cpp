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

int gen(vector<int> v, int mid) {
    int res = 0;
    for (int i=0; i<v.size(); i++) {
        res += ceil(v[i] * 1.0 / mid);
    }
    return res;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<int> v = {3,6,7,11};
        int H = 8;
        int lo = 1, hi = -1;
        for (int i=0; i<v.size(); i++) {
            hi = max(hi, v[i]);
        }
        int res = INT_MAX;
        while (lo <= hi) {
            cout << lo << ' ' << hi << '\n';
            int mid = lo + (hi - lo)/2;
            int ans = gen(v, mid);
            cout << ans << '\n';
            if (ans <= H) {
                lo = mid + 1;
                res = min(res, mid);
            } else {
                hi = mid - 1;
            }
        }
        cout << res << '\n';
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
