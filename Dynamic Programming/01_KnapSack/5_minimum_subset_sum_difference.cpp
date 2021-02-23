#include <bits/stdc++.h>
using namespace std;

vector<int> subsetsum(vector<int>& v, int range) {
    int n = v.size();
    vector<vector<bool>> dp(n+1, vector<bool> (range+1));

    for (int i=0; i<=n; i++) dp[i][0] = true;
    for (int j=1; j<=range; j++) dp[0][j] = false;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=range; j++) {
            if (v[i-1] <= j) dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> res;
    for (int j=0; j<=(range/2); j++) {
        if (dp[n][j]) res.push_back(j);
    }
    return res;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1, 2, 7};
    int n = v.size();
    int range = 0;
    for (int i=0; i<n; i++) {
        range += v[i];
    }
    vector<int> s1 = subsetsum(v, range);
    int mn = INT32_MAX;
    for (int i=0; i<s1.size(); i++) {
        mn = min(mn, range - 2*s1[i]);
    }
    cout << mn << "\n";
    
    return 0;
}
