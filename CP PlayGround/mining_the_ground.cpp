#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define f first
#define s second
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

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> dp(n+1,0);
        int m = 1000000007;
        if (n == 1) {
            cout << dp[n]%m << '\n';
        } else if (n == 2) {
            dp[2] = 1;
            cout << dp[2]%m << '\n';
        } else if (n == 3) {
            dp[3] = 1;
            cout << dp[3]%m << '\n';
        } else {
            dp[2] = 1;
            dp[3] = 1;
            dp[4] = 1;
            for (int i=5; i<=n; i++) {
                int sum = (dp[i-2]%m + dp[i-3]%m)%m;
                dp[i] = sum;
            }
            cout << dp[n] << '\n';
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
        // freopen("out1", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}
