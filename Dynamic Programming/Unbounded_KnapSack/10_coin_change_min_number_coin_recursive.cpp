#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> coin = {9,6,5,1};
    int sum = 11;
    // vector<int> coin= {15,10,5};
    // int sum = 30;
    int n = coin.size();
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for (int j=0; j<=sum; j++) {
        dp[0][j] = INT32_MAX-1;
    }
    for (int i=1; i<=n; i++) {
        dp[i][0] = 0;
    }
    for (int j=1; j<=sum; j++) {
        if (j%coin[0] == 0) dp[1][j] = j/coin[0];
        else dp[1][j] = INT32_MAX-1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if (coin[i-1] <= j) {
                dp[i][j] = min(1+dp[i][j-coin[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][sum] << "\n";

    return 0;
}
