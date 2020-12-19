#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, j=1;
    cin >> t;
    while (t--) {
        int n, b;
        cin >> n >> b;
        vector<int> v(n);
        // int ar[n];
        for (int i=0; i<n; i++) {
            // cin >> ar[i];
            cin >> v[i];
        }
        // sort(ar, ar+n);
        sort(v.begin(), v.end());
        int sum=0, inr=0, i=0;
        while (sum <= b) {
            sum += v[i];
            inr++;
            i++;
        }
        cout << "Case #" << j << ": " << inr-1 << "\n";j++;
    }

    return 0;
}
