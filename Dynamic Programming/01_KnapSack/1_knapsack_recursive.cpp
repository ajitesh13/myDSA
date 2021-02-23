#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<vector<ll>> dp;

ll knapsack(vector<ll> wt, vector<ll> val, ll W, ll n) {
    if (dp[n][W] != -1) {
        return dp[n][W];
    } else {
        if (n == 0 || W == 0) {
            return dp[n][W] = 0;
        }
        if (wt[n-1] <= W) {
            return dp[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
        } else {
            return dp[n][W] = knapsack(wt, val, W, n-1);
        }
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, W;
    cin >> n >> W;
    vector<ll> val(n), wt(n);
    for (int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
    }
    dp.assign(n+1, vector<ll> (W+1, -1));
    cout << knapsack(wt, val, W, n) << '\n';
    
    return 0;
}
