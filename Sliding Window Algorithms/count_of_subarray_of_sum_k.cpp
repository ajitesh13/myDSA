#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1,1,1};
    int k = 2;
    int n = v.size();

    unordered_map<int,int> ump;
    int res = 0, sum = 0;
    ump[0] = 1;
    for (int i=0; i<n; i++) {
        sum += v[i];
        cout << sum << " ";
        if (ump.find(sum-k) != ump.end()) {
            res += ump[sum-k];
        }
        if (ump.find(sum) == ump.end()) {
            ump.insert({sum,1});
        } else ump[sum]++;
    }
    cout << res << "\n";

    return 0;
}
