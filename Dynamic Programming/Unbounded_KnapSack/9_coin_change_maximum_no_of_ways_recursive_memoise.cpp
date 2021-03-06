#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int coinchange(vector<int>& v, int sum, int n) {
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    } else {
        if (n == 0 && sum == 0) return dp[n][sum] = 1;
        else if (n == 0) return dp[n][sum] = 0;
        else {
            if (v[n-1] <= sum) {
                return dp[n][sum] = coinchange(v, sum-v[n-1], n) + coinchange(v, sum, n-1);
            } else return dp[n][sum] = coinchange(v, sum, n-1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector<int> v = {1,2,3}; int sum = 4; // 4
    vector<int> v = {2,5,3,6}; int sum = 10; // 5
    // vector<int> v = {1,2,3}; int sum = 5; // 5
    int n = v.size();
    dp.assign(n+1, vector<int> (sum+1, -1));
    cout << coinchange(v, sum, n) << "\n";
    
    return 0;
}
