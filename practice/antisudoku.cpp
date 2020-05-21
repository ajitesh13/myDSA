// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int tc = 1;
    int t;
    cin >> t;
    while (t--) {
        vector<string> v(9);
        for (int i=0; i<9; i++) {
            cin >> v[i];
        }
        map<int,int> m;
        map<int,int>::iterator it;
        m.insert(make_pair(0,0));
        m.insert(make_pair(1,3));
        m.insert(make_pair(2,6));
        m.insert(make_pair(3,1));
        m.insert(make_pair(4,4));
        m.insert(make_pair(5,7));
        m.insert(make_pair(6,2));
        m.insert(make_pair(7,5));
        m.insert(make_pair(8,8));
        int a, b;
        for (it = m.begin(); it != m.end(); it++) {
            a = it->first;
            b = it->second;
            if (v[a][b] == '1') {
                v[a][b] = '2';
            } else {
                v[a][b] = '1';
            }
        }
        for (int i=0; i<9; i++) {
            cout << v[i] << endl;
        }
    }
    
    return 0;
}