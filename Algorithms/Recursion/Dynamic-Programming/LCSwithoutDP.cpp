#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int val;
    if(n == 0 || m == 0) {
        val = 0;
    }
    if(n > 0 && m > 0) {
        if(s1[n-1] == s2[m-1]) {
            val = 1 + lcs(s1.substr(0,n-1), s2.substr(0,m-1));
        } else if (s1[n-1] != s2[m-1]) {
            val = max(lcs(s1.substr(0, n-1), s2.substr(0, m)), lcs(s1.substr(0, n), s2.substr(0, m-1)));
        }
    }
    return val;
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
