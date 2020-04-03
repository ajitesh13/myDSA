#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        int input;
        for(int i=0; i<n; i++) {
            cin >> input;
            v.push_back(input);
        }
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(v[i] == 1) {
                res.push_back(i);
            }
            else {
                continue;
            }
        }
        for(int i=0; i<res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        int inr=0;
        for(int i=0; i<res.size(); i++) {
            if(abs(res[i]-res[i+1]) < 6) {
                cout << "NO" << endl;
                inr++;
                break;
            } else {
                continue;
            }
        }
        if(inr == 0) {
            cout << "YES" << endl;
        }
    }
    return 0;
}
