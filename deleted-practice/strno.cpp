#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;
        int inr=0;
        while (x % 2 == 0) {
            // cout << 2 << " ";
            inr++;
            x = x/2;
        }
        for (int i=3; i <= sqrt(x); i=i+2) {
            while (x % i == 0) {
                // cout << i << " ";
                inr++;
                x = x/i;
            }
        }
        if (x > 2) {
            // cout << x << " ";
            inr++;
        }
        if (inr >= k) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
