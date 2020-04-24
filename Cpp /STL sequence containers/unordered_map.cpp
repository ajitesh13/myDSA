// implimented using hash table
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_multimap<int, int> um;
    um.insert(pair<int,int>(1,40));
    um.insert(pair<int,int>(4,90));
    um.insert(pair<int,int>(2,30));
    um.insert(pair<int,int>(4,50));

    for (auto it = um.begin(); it != um.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}
