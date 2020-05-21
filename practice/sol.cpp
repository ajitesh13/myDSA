// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int unsigned long long
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
        vector<int> v = { 1 };
        int temp = 0, x;

        for (int i=2; i<=n; i++) {
            for (int j=0; j<v.size(); j++) {
                x = v[j]*i + temp;
                v[j] = x % 10;
                temp = x / 10;
            }
            if (temp != 0) {
                v.push_back(temp);
                temp = 0;
            }
        }

        for (int i=0; i<v.size(); i++) {
            cout << v[v.size()-1-i];
        }
        cout << endl;
    }

    return 0;
}
