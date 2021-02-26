#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixsum2d(vector<vector<int>>& v, int n, int m) {
    vector<vector<int>> prefix(n, vector<int> (m, 0));
    prefix[0][0] = v[0][0];
    for (int j=1; j<m; j++) prefix[0][j] = prefix[0][j-1] + v[0][j];
    for (int i=1; i<n; i++) prefix[i][0] = prefix[i-1][0] + v[i][0];
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + v[i][j];
        }
    } 
    return prefix;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> v = {{10,20,30},{5,10,20},{2,4,6}};
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> prefix = prefixsum2d(v, n, m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << prefix[i][j] << " ";
        }
        cout << "\n";
    }
    int top = 1, bottom = 2, left = 1, right = 2;
    cout << prefix[bottom][right]-prefix[top-1][right] - prefix[bottom][left-1]+prefix[top-1][left-1] << "\n";
    
    return 0;
}
