#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1;
    cin >> s1;
    int n = s1.length();

    cout << s1[n-1] << endl;
    cout << s1.substr(0, n) << endl;
    return 0;
}
