// always remember that matrix count starts from 1
// but the matrix dimension count starts from 0
#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> v, int n) {
    int dp[n][n];
    if (i == j) return 0;
    int min = INT_MAX;
    int k, res, i, j;
    for (int i=1; i<n; i++) dp[i][i] = 0;
    // L is chain length
    for (int L=2; L<n; L++) {
        for (int i=1; i<n-L+1; i++) {
            j = i + L - 1;
            dp[i][j] = min;
            for (k=i; k <= j-1; k++) {
                res = dp[i][k] + dp[k+1][j] + v[i-1] * v[k] * v[j];
                if (res < dp[i][j]) {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0;i<n; i++) cin >> v[i];
        cout << mcm(v, 1, n-1) << endl;
    }
    return 0;
}