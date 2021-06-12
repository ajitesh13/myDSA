#include <bits/stdc++.h>
#define int long long int 
using namespace std;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {9,6};
    int S = 0;
    for (auto i: v) S += i;
    int n = v.size();
    S /= 2;
    int dp[n+1][S+1];
    dp[0][0] = 0;
    for (int i=0; i<=n; i++) {
        dp[i][0] = 0;
    }
    for (int j=1; j<=S; j++) {
        dp[0][j] = INT32_MAX;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=S; j++) {
            if (v[i-1] <= j) { 
                dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-v[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            
        }
    }
    cout << dp[n][S] << "\n";
    
    return 0;
}
