#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<char,int> ump1, ump2;
    ump1['s'] = 1;
    ump1['a'] = 2;
    ump2['s'] = 1;
    ump2['a'] = 2;
    if (ump1 == ump2) cout << 1 << "\n";
    else cout  << 2 << "\n";
    return 0;
}
