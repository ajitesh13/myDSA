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

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return(
        p1.first < p2.first
    );
}

int lis(vector<int> s) {
    int res = 0;
    vector<int> dp(s.size(), 1);
    for (int j=0; j<s.size(); j++) {
        for (int i=0; i<j; i++) {
            if (s[i] <= s[j]) {
                if (dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        res = max(res, dp[j]);
    }
    return res;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int,int>> c;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        for (int i=0; i<n; i++) {
            c.push_back(make_pair(a[i], b[i]));
        }
        sort(c.begin(), c.end(), cmp);
        // for (int i=0; i<n; i++) {
        //     cout << c[i].first << ' ' << c[i].second << '\n';
        // }
        vector<int> res;
        for (auto it=c.begin(); it!=c.end(); it++) {
            res.push_back(it->second);
        }
        cout << lis(res) << '\n';
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
