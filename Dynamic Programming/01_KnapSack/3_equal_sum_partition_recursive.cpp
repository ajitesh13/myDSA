#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int>& nums, int sum, int n) {
    if (n == 0 && sum != 0) return false;
    else if (sum == 0) return true;
    else {
        if (nums[n-1] <= sum) 
            return subsetsum(nums, sum-nums[n-1], n-1) || subsetsum(nums, sum, n-1);
        else return subsetsum(nums, sum, n-1);
    }
}
bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        sum += nums[i];
    }
    if (sum%2 != 0) return false;
    sum = sum/2;
    return subsetsum(nums, sum, n);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << "\n";
    
    
    return 0;
}
