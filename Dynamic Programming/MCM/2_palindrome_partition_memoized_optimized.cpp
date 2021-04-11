#include <bits/stdc++.h>
using namespace std;

bool ispal(string s, int i, int j) {
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else return false; 
    }
    return true;
}

vector<vector<int>> dp;
int palindromepartition(string s, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    } else {
        if (i >= j) 
        return 0;
        if (ispal(s, i, j)) 
            return 0;
        int mn = INT32_MAX;
        for (int k=i; k<=j-1; k++) {
            int left, right;
            if (dp[i][k] == -1) dp[i][k] = palindromepartition(s, i, k);
            left = dp[i][k];
            if (dp[k+1][j] == -1) dp[k+1][j] = palindromepartition(s, k+1, j);
            right = dp[k+1][j];  
            int tempans = 1 + left + right;
            mn = min(mn, tempans);
        }
        return mn;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "ab  cd";
    int n = s.size();
    dp.assign(n+1, vector<int> (n+1, -1));
    cout << palindromepartition(s, 0, n-1) << "\n";
    
    return 0;
}
