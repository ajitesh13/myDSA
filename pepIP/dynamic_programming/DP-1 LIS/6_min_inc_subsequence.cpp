// min. inc subsequence will be equal to the longest decreasing subsequence
#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

int lds(vector<int> nums) {
    int res = 0;
    vector<int> dp(nums.size(), 1);
    for (int j=0; j<nums.size(); j++) {
        for (int i=0; i<j; i++) {
            if (nums[i] > nums[j]) {
                if (dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        res = max(res, dp[j]);
    }
    return res;
}

int main() {
    vector<int> nums = {8, 4, 1, 2, 9};
    cout << lds(nums) << '\n';
    return 0;
}