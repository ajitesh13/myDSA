#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    int tc=1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        int inr=0;
        for (int i=0; i<n; i++) {
            if (i != 0 && i != n-1) {
                if (v[i-1] < v[i] && v[i] > v[i+1]) {
                    inr++;
                }
            }
        }
        cout << "Case #" << tc << ": " << inr << "\n";tc++;
    }

    return 0;
}
