#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int countsubsetsum(vector<int>& v, int n, int sum) {
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    } else {
        if (n == 0 and sum == 0) return dp[n][sum] = 1;
        else if (n == 0) return dp[n][sum] = 0;
        else {
            if (v[n-1] <= sum) return dp[n][sum] = countsubsetsum(v, n-1, sum-v[n-1]) + countsubsetsum(v, n-1, sum);
            else return dp[n][sum] = countsubsetsum(v, n-1, sum);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {0,0,0,0,0,0,0,0,1};    
    int n = v.size();
    int sum = 1;
    dp.assign(n+1, vector<int> (sum+1, -1));
    cout << countsubsetsum(v, n, sum) << "\n";
    
    return 0;
}
