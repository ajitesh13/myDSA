#include <bits/stdc++.h>
using namespace std;

void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m));
        vector<pair<int,int>> vep = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int def = 0;
                for (int k=0; k<vep.size(); k++) {
                    if (i + vep[k].first >= 0 && j + vep[k].second >= 0) {
                        if (i + vep[k].first < n && j + vep[k].second < m) {
                            def++;
                        }
                    } 
                }
                v[i][j] = def;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
}

int main() {
    
    best();
    
    return 0;
}
