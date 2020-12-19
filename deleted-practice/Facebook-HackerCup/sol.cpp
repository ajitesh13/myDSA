// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int tc = 1;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        string b;
        cin >> b;
        vector<vector<char>> p(n, vector<char> (n, 'F'));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) {
                    p[i][j] = 'Y';
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (i == 0) {
                p[i+1][i] = a[i];
            } else if (i == n-1) {
                p[i-1][i] = a[i];
            } else {
                p[i-1][i] = a[i];
                p[i+1][i] = a[i];
            }
        }
        for (int i=0; i<n; i++) {
            if (b[i] == 'N') {
                if (i == 0) {
                    p[i][i+1] = b[i];
                } else if (i == n-1) {
                    p[i][i-1] = a[i];
                } else {
                    p[i][i-1] = b[i];
                    p[i][i+1] = b[i];
                }
            }
        }
        // only the special task remain to do
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << p[i][j];
            }
            cout << endl;
        }



        // cout << "Case #" << tc << ": " <<<< "\n"; tc++;
    }
    
    return 0;
}