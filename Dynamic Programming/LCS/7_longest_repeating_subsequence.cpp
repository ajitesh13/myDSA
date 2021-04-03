#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string X = "AABEBCDD";
    int n = X.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (X[i-1] == X[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1]; 
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][n] << "\n";
    
    return 0;
}
