#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int q;
    cin >> q;
    int len = (int) sqrt (n + .0) + 1;
    vector<int> sq(len, INT32_MAX);
    for (int i=0; i<n; i++) {
        sq[i/len] = min(v[i], sq[i/len]);
    }
    while (q--) {
        int l, r, ans = INT32_MAX;
        cin >> l >> r;
        while (l <= r) {
            if (l%len == 0 && l+len-1 <= r) {
                ans = min(sq[l/len], ans);
                l += len;
            } else {
                ans = min(v[l], ans);
                l++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
