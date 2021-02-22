#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> dp;

bool subsetsum(vector<int> v, int n, int sum) {
    if (n == 0) return dp[n][sum] = false;
    else if (sum == 0) return dp[n][sum] = true;
    else {
        if (v[n-1] <= sum) return dp[n][sum] = subsetsum(v, n-1, sum-v[n-1]) || subsetsum(v, n-1, sum);
        else return dp[n][sum] = subsetsum(v, n-1, sum);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {3, 34, 4, 12, 5, 2};
    int n = v.size();
    int sum = 37;
    dp.assign(n+1, vector<bool> (sum+1));
    cout << subsetsum(v, n, sum) << "\n";
    
    return 0;
}
