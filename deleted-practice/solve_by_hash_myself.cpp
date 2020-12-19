// may challenge prob a
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int b[n] = {0};
        for (int i=0; i<n; i++)
            cin >> v[i];
        int k = 0, clst = 1;
        b[k] = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] - v[i-1] <= 2) {
                b[k]++;
            } else {
                k++;
                b[k]++;
                clst++;
            }
        }
        int max = -1;
        int min = INT_MAX;
        for (int i=0; i<clst; i++) {
            if (b[i] >= max) {
                max = b[i];
            }
            if (b[i] <= min) {
                min = b[i];
            }
        }
        cout << min << " " << max << endl;
    }

    return 0;
}