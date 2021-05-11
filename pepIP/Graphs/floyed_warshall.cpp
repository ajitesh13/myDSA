#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(n, vector<int> (n, INT32_MAX));
    for (int i=0; i<e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x][y] = z;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) v[i][j] = 0;
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == k || j == k || v[i][k] == INT32_MAX || v[k][j] == INT32_MAX) {
                    continue;
                }
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (v[i][j] == INT32_MAX) cout << "INF" << " ";
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }


    
    return 0;
}
