#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {1,1,1};
    int k = 2;
    int n = nums.size();
    vector<int> pfs(n);
    pfs[0] = nums[0];
    for (int i=1; i<n; i++) {
        pfs[i] = pfs[i-1] + nums[i];
    }
    unordered_map<int,int> ump;
    int ans = 0;
    ump[0] = 1;
    for (int j=0; j<n; j++) {
        cout << pfs[j] << " ";
        if (ump.find(pfs[j] - k) != ump.end()) {
            ans += ump[pfs[j] - k];
        }
        if (ump.find(pfs[j]) == ump.end()) {
            ump.insert(make_pair(pfs[j], 1));
        } else {
            ump[pfs[j]]++;
        }
    }
    cout << ans << "\n";
}
