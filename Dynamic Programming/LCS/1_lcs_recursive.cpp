#include <bits/stdc++.h>
using namespace std;

int lcs(string a, int n, string b, int m) {
    if (n == 0 || m == 0) return 0;
    else {
        if (a[n-1] == b[m-1]) {
            return 1 + lcs(a,n-1,b,m-1);
        } else {
            return max(lcs(a,n-1,b,m),lcs(a,n,b,m-1));
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "abaacab";
    string b = "bacac";
    int n = a.size();
    int m = b.size();
    cout << lcs(a,n-1,b,m-1) << "\n";
    
    return 0;
}
