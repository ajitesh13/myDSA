#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int lcs(string text1, int n, string text2, int m) {
    if (dp[n][m] != -1) {
        return dp[n][m];
    } else {
        if (n == 0 || m == 0) 
            return dp[n][m] = 0;
        if (text1[n-1] == text2[m-1]) 
            return dp[n][m] = 1 + lcs(text1, n-1, text2, m-1);
        else 
            return dp[n][m] = max(lcs(text1, n, text2, m-1), lcs(text1, n-1, text2, m));
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "AGGTAB";
    string b = "GXTXAYB";
    int n = a.size();
    int m = b.size();
    dp.assign(n+1, vector<int> (m+1, -1));
    cout << lcs(a,n,b,m) << "\n";
    
    return 0;
}
