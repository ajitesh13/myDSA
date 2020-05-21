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
        vector<int> v(n+1);
        int x;
        for (int i=0; i<n; i++) {
            cin >> x;
            v[x]++;
        }
        int a = 0;
        for (int i=0; i<n+1; i++) {
            if (v[i] != 0) {
                a++;
            }
        }
        int b = *max_element(v.begin(), v.end());
        int res;
        if (a == b) {
            res = a-1;
        } else {
            res = min(a, b);
        }
        cout << res << endl;
    }

    return 0;
}