#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(int e, int f) {
    if (f == 0 or f == 1) return dp[e][f] = f;
    if (e == 1) return dp[e][f] = f;
    if (dp[e][f] != -1) {
        return dp[e][f];
    } else {
        int mn = INT32_MAX;
        for (int k=1; k<=f; k++) {
            int eggbreak, noteggbreak;
            if (dp[e-1][k-1] == -1) dp[e-1][k-1] = solve(e-1, k-1);
            eggbreak = dp[e-1][k-1];
            if (dp[e][f-k] == -1) dp[e][f-k] = solve(e, f-k);
            noteggbreak = dp[e][f-k];
            int tempans = 1 + max(eggbreak, noteggbreak);
            mn = min(mn, tempans);
        }
        return dp[e][f] = mn;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e = 2, f = 36;
    memset(dp, -1, sizeof(dp));
    cout << solve(e, f) << "\n";
    
    return 0;
}
