#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    unordered_map<int,int> ump;
    ump.insert({1, 2});

    for (auto [x, y]: ump) {
        cout << x << " " << y << "\n";
    }
    
    return 0;
}
