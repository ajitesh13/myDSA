// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
// #define ll long long int
#define int long long 
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

int kadane(vector<int> nums) {
    int osum = nums[0], csum = nums[0];
    for (int i=1; i<nums.size(); i++) {
        if (csum < 0) {
            csum = nums[i];
        } else {
            csum += nums[i];
        }
        osum = max(osum, csum);
    }
    return osum;
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        for (int i=0; i<n; i++) {
            b.pb(a[i]);
        }
        int kadaneval = kadane(b);
        int tsum = 0;
        for (int i=0; i<n; i++) {
            tsum += a[i];
        }
        if (tsum > 0) {
            cout << (k-2)*tsum + kadaneval << '\n';
        } else {
            cout << kadaneval << '\n';
        }
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

signed main() {
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
