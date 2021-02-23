#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += nums[i];
    }
    if (sum%2 != 0) return false;
    sum /= 2;
    vector<vector<bool>> dp(n+1, vector<bool> (sum + 1));
    for (int i=0; i<=n; i++) {
        dp[i][0] = true;
    }
    for (int j=1; j<=sum; j++) {
        dp[0][j] = false;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if (nums[i-1] <= j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[n][sum];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << "\n";
    
    
    return 0;
}
