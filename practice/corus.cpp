// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int ar[130] = {0};
        for (int i=0; i<n; i++) {
            ar[int(s[i])]++;
        }
        vector<int> v;
        for(int i=97; i<=122; i++) {
            if (ar[i] >= 1)
                v.push_back(ar[i]);
        }
        while (q--) {
            long long int c, sum = 0;
            cin >> c;
            vector<long long> b(v.begin(), v.end());
            for (int i=0; i<b.size(); i++) {
                if ((b[i] - c) < 0) {
                    b[i] = 0;
                } else {
                    b[i] = b[i] - c;
                }
                sum += b[i];
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}