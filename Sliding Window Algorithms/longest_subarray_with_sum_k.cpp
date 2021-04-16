#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {12,-6,2,2,4,4,1,1,5};
    int k = 7;
    int n = v.size();

    unordered_map<int,int> ump;
    int ans = 0, sum = 0;
    for (int i=0; i<n; i++) {
        sum += v[i];
        if (sum == k) ans = i+1;
        if (ump.find(sum) == ump.end()) {
            ump.insert({sum, i});
        }    
        if (ump.find(sum-k) != ump.end()) {
            ans = max(ans, i-ump[sum-k]);
        }
    } 
    cout << ans << "\n";

    return 0;
}
