#include <bits/stdc++.h>
using namespace std;

int countofsubsetsum(vector<int>& v, int sum) {
    int n = v.size();
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for (int i=0; i<=n; i++) dp[i][0] = 1;
    for (int j=1; j<=n; j++) dp[0][j] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if (v[i-1] <= sum) dp[i][j] = dp[i-1][j-v[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1, 1, 2, 3};
    int diff = 1;
    int n = v.size();
    int range = 0;
    for (int i=0; i<n; i++) {
        range += v[i];
    }
    cout << countofsubsetsum(v, (diff+range)/2) << "\n";
    
    return 0;
}
