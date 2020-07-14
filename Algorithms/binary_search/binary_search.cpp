#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> ar(a);
    vector<int> br(b);
    for (int i=0; i<a; i++) {
        cin >> ar[i];
    }
    for (int j=0; j<b; j++) {
        cin >> br[j];
    }
    int res;
        sort(ar.begin(), ar.end());
        for (int i=0; i<b; i++) {
            auto it = upper_bound(ar.begin(), ar.end(), br[i]);
            res = (it - ar.begin());
            cout << res << " ";
    }
    cout << endl;
    return 0;
}
