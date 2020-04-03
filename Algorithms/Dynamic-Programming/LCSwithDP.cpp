// lcs with dp
#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int c[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0) {
                c[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    int index = c[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    int i=m;
    int j=n;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            lcs[index-1] = s1[i-1];
            i--;j--;index--;
        } else if(c[i-1][j] > c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << lcs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    string s1="Ajitesh", s2="Ajit";
    // cin >> s1 >> s2;
    lcs(s1, s2);
    return 0;
}



