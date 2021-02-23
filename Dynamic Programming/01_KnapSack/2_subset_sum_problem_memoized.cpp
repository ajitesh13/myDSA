#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool subsetsum(vector<int> v, int n, int sum) {
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    } else {
        if (n == 0 && sum != 0) return dp[n][sum] = 0;
        else if (sum == 0) return dp[n][sum] = 1;
        else {
            if (v[n-1] <= sum) return dp[n][sum] = (subsetsum(v, n-1, sum-v[n-1]) || subsetsum(v, n-1, sum));
            else return dp[n][sum] = subsetsum(v, n-1, sum);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1,2,5};
    int n = v.size();
    int sum = 4;
    dp.assign(n+1, vector<int> (sum+1, -1));
    cout << subsetsum(v, n, sum) << "\n";
    
    return 0;
}
