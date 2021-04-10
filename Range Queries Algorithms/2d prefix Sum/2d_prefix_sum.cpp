#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixsum2d(vector<vector<int>>& v) {
    int m = v[0].size();
    int n = v.size();
    vector<vector<int>> res(n, vector<int> (m));
    res[0][0] = v[0][0];
    for (int i=1; i<n; i++) {
        res[i][0] = v[i][0] + res[i-1][0];
    }
    for (int j=1; j<m; j++) {
        res[0][j] = v[0][j] + res[0][j-1];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + v[i][j];
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }

    // calculating 2d prefix sum array
    vector<vector<int>> res = prefixsum2d(v);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    // answering queries
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int k = res[r2][c2] - res[r2][c1-1] - res[r1-1][c2] + res[r1-1][c1-1];
    cout << k << "\n";

    return 0;
}
