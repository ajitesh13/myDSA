#include <bits/stdc++.h>
using namespace std;

int lcs(string text1, int n, string text2, int m) {
    if (n == 0 || m == 0) 
        return 0;
    if (text1[n-1] == text2[m-1]) 
        return 1 + lcs(text1, n-1, text2, m-1);
    else 
        return max(lcs(text1, n, text2, m-1), lcs(text1, n-1, text2, m));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "abaacab";
    string b = "bacac";
    int n = a.size();
    int m = b.size();
    cout << lcs(a,n,b,m) << "\n";
    
    return 0;
}
