#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, W;
    cin >> n >> W;
    vector<int> wt(n+1), val(n+1);
    for (int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W] << "\n";
    
    return 0;
}
