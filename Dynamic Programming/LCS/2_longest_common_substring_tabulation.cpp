#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "ajiteshtyui";
    string b = "tyuiajiteshityui";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    int res = 0;
    for (int i=0; i<=n; i++) dp[i][0] = 0;
    for (int j=0; j<=m; j++) dp[0][j] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(res, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout << res << "\n";
    
    return 0;
}
