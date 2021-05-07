#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == k || j == k || v[i][k] == INT_MAX || v[k][j] == INT_MAX) {
                    continue;
                }
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
