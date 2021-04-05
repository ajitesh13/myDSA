#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> ar, int i, int j) {
    if (i >= j) 
        return 0;
    else {
        int mn = INT32_MAX;
        for (int k=i; k<=j-1; k++) {
            int tempans = solve(ar,i,k) + solve(ar,k+1,j) + ar[i-1]*ar[k]*ar[j];
            mn = min(mn, tempans);
        }
        return mn;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector<int> ar = {1,2,3,4,3}; // 30
    vector<int> ar = {1,2,3,4}; // 18
    int n = ar.size();
    cout << solve(ar, 1, n-1) << "\n";
    
    return 0;
}
