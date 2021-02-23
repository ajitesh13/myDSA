#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1,2,7};
    int n = v.size();
    int sum = 10;
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for (int i=0; i<=n; i++) {
        dp[i][0] = true;
    }
    for (int j=1; j<=sum; j++) {
        dp[0][j] = false;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if (v[i-1] <= j) dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum] << "\n";
    
    return 0;
}
