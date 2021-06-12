#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];
int solve(string s, int i, int j, bool istrue) {
    if (j < i) return dp[i][j][istrue] = 0;
    if (i == j) {
        if (istrue == true) {
            if (s[i] == 'T') {
                return dp[i][j][istrue] = 1;
            } else return dp[i][j][istrue] = 0;
        } else {
            if (s[i] == 'F') {
                return dp[i][j][istrue] = 1;
            } else return dp[i][j][istrue] = 0;
        }
    }
    if (dp[i][j][istrue] != -1) {
        return dp[i][j][istrue];
    } else {
        int ans = 0;
        for (int k=i+1; k<=j-1; k++) {
            if (s[k] != 'T' and s[k] != 'F') {
                int lt = solve(s, i, k-1, true);
                int lf = solve(s, i, k-1, false);
                int rt = solve(s, k+1, j, true);
                int rf = solve(s, k+1, j, false);
                if (s[k] == '&') {
                    if (istrue == true) {
                        ans += lt*rt;
                    } else ans += lf*rt + lt*rf + lf*rf;
                } else if (s[k] == '|') {
                    if (istrue == true) {
                        ans += lt*rf + lf*rt + lt*rt;
                    } else ans += lf*rf;
                } else if (s[k] == '^') {
                    if (istrue == true) {
                        ans += lt*rf + lf*rt;
                    } else ans += lf*rf + lt*rt;
                }
            }
        }
        return dp[i][j][istrue] = ans;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "T|T&F^T"; // 4
    // string s = "T^F|F"; // 2
    // string s = "T^F&T"; // 2
    memset(dp,-1, sizeof(dp));
    cout << solve(s, 0, s.length()-1, true);
    
    return 0;
}
