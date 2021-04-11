#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(vector<int> ar, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    } else {
        if (i >= j) 
            return 0;
        else {
            int mn = INT32_MAX;
            for (int k=i; k<=j-1; k++) {
                int tempans = solve(ar,i,k) + solve(ar,k+1,j) + ar[i-1]*ar[k]*ar[j];
                mn = min(mn, tempans);
            }
            return dp[i][j] = mn;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> ar = {1,2,3,4,3}; // 30
    // vector<int> ar = {1,2,3,4}; // 18
    int n = ar.size();
    dp.assign(n+1, vector<int> (n+1, -1));
    cout << solve(ar, 1, n-1) << "\n";
    
    return 0;
}
