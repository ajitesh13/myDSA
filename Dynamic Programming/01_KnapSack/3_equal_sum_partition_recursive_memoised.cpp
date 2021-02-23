#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int subsetsum(vector<int> v, int n, int sum) {
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    } else {
        if (n == 0 && sum != 0) return dp[n][sum] = 0;
        else if (sum == 0) return dp[n][sum] = 1;
        else {
            if (v[n-1] <= sum) return dp[n][sum] = subsetsum(v, n-1, sum-v[n-1]) || subsetsum(v, n-1, sum);
            else return dp[n][sum] = subsetsum(v, n-1, sum);
        }
    }
}
bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        sum += nums[i];
    }
    if (sum%2 != 0 ) return false;
    sum = sum/2;
    dp.assign(n+1, vector<int> (sum+1, -1));
    int res = subsetsum(nums, n, sum);
    if (res) return true;
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << "\n";
    
    
    return 0;
}
