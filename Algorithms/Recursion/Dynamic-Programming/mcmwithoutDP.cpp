// always remember that matrix count starts from 1
// but the matrix dimension count starts from 0
#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> v, int i, int j) {
    if (i == j) return 0;
    int min = INT_MAX;
    int k, res;
    for (int k=i; k<j; k++) {
        res = v[i-1] * v[k] * v[j] + mcm(v, i, k) + mcm(v, k+1, j);
        if (res < min) min = res;
    }
    return res;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0;i<n; i++) cin >> v[i];
        cout << mcm(v, 1, n-1) << endl;
    }
    return 0;
}