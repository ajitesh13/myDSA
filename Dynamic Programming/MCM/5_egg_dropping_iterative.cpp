#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e = 2, f = 10;
    int A = e;
    int B = f;

    int dp[3][11];
    for (int i=0; i<=A; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j=0; j<=B; j++) {
        dp[1][j] = j;
    }
    for (int i=2; i<=A; i++) {
        for (int j=2; j<=B; j++) {
            int mn = INT32_MAX;
            for (int k=1; k<=j; k++) {
                int tempans = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                mn = min(mn, tempans);
            }
            dp[i][j] = mn;
        }
    }
   
    for (int i=1; i<=2; i++) {
        for (int j=0; j<=10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
