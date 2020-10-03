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

static bool cmp(tuple<int,int,int> t1, tuple<int,int,int> t2) {
    return(get<0>(t1) < get<0>(t2));
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<tuple<int,int,int>> vt = {
            {1, 2, 50},
            {3, 5, 20},
            {6, 19, 100},
            {2, 100, 200}
        };
        sort(vt.begin(), vt.end(), cmp);
        int sum = 0;
        vector<int> dp(vt.size());
        for (int i=0; i<vt.size(); i++) {
            dp[i] = get<2>(vt[i]);
        }
        for (int j=0; j<vt.size(); j++) {
            for (int i=0; i<j; i++) {
                if (get<1>(vt[i]) < get<1>(vt[j])) {
                    if (dp[i] + get<2>(vt[i]) > dp[j]) {
                        dp[j] = dp[i] + get<2>(vt[i]);
                    }
                }
            }
            sum = max(sum, dp[j]);
        }
        cout << sum << '\n';
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
