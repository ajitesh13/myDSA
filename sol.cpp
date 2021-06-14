#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string x = "AS";
    string y = "ZF";
    string res1 = x + ' ' + y;
    string res2 = x;
    res2.push_back(' ');
    res2.append(y);
    cout << res1 << "\n";
    cout << res2 << "\n";
    
    return 0;
}
