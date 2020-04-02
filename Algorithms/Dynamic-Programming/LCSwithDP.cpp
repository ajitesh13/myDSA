// lcs with dp
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int c[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++) {
        for(j=0; j<=n; j++) {
            if(i==0 || j==0) {
                c[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    return c[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    return 0;
}



