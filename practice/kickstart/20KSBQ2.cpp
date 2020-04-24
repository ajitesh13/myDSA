#include <bits/stdc++.h>
#define int long 
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    int tc=1;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        int i = n-1, res, in;
        if (n == 1) {
            cout << "Case #" << tc << ": " << 1 << "\n"; tc++;
            continue;
        } else {
            while (i >= 0) {
                in = d % v[i];
                if (in != 0) {
                    d--;
                    continue;
                } else {
                    res = d;
                    i--;
                }
            }
        }
        cout << "Case #" << tc << ": " << res << "\n"; tc++;
    }

    return 0;
}
