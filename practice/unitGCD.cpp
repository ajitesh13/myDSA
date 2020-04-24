#include <bits/stdc++.h>
#define int long long
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
        int a = n, ans = n/2;
        if (n == 1) {
            ans = 1;
            cout << "1 1" << "\n";
        } else {
            cout << ans << "\n";
        }
        if (n == 2) {
            cout << "2 1 2" << "\n";
        } else if (n == 3) {
            cout << "3 1 2 3" << "\n";
        } else if (n > 3){
            cout << "3 1 2 3" << "\n";
            a = 4;
            for (int i=2; i<=(ans-1); i++) {
                cout << "2 "<<a << " " << (a+1) << "\n";
                a = a + 2;
            }
            if (n % 2 == 0) {
                cout << 1 << " " <<a << "\n";
            } else {
                cout << 2 << " " << a << " " << (a+1) << "\n";
            }
        }
    }
    
    return 0;
}
