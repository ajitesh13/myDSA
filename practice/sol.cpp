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
        int e = 2, sume = 0;
        int o = 1, sumo = 0;
        vector<int> v;
        for (int i=1; i<=n/2; i++) {
            v.push_back(e);
            sume += e;
            e += 2;
        }
        for (int i=(n/2+1); i<=n-1; i++) {
            v.push_back(o);
            sumo += o;
            o += 2;
        }
        if ((sume - sumo) % 2 != 0) {
            cout << "YES" << endl;
            v.push_back(sume-sumo);
            for (int i=0; i<n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}