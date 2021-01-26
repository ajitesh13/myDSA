#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    vector<tuple<int,int,int>> v(n);
    for (int i=0; i<n; i++) {
        cin >> get<0>(v);
    }
    
    return 0;
}
