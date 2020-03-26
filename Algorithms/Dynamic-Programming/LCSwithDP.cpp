// debug it and add printing the subsequence part
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int c[n+1][m+1];
    for(int j=0; j<n; j++) {
        for(int i=0; i<m; i++) {
            if(n == 0 || j == 0) {
                c[j][i] == 0;
            } else if(s1[n-1] == s2[m-1]) {
                c[j][i] = 1 + c[j-1][i-1];
            } else if(s1[n-1] != s2[n-1]) {
                c[j][i] = max(c[j-1][i], c[j][i-1]);
            }
        }
    }
    return c[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << lcs(s1, s2) << endl;
    
    return 0;
}
