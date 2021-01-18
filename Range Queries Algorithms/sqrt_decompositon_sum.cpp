#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {3,1,4,-1,2,3,5,-4,1,-5,4,3,2,-1,-3,1,4,-2,6,1,3,-2};
    int n = v.size();
    int len = (int) sqrt (n + .0) + 1;
    vector<int> sq(len, 0);
    for (int i=0; i<n; i++) {
        sq[i/len] += v[i];
    }
    
    int l = 1, r = 18, ans = 0;
    while (l <= r) {
        if (l%len == 0 && l+len-1 <= r) {
            ans += sq[l/len];
            l += len;
        } else {
            ans += v[l];
            l++;
        }
    }
    cout << ans << '\n';
    
    
    return 0;
}
