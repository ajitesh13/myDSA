#include <bits/stdc++.h>
using namespace std;

int go(int x1, int ans) {
    long long int t = 1;
    int x2 = 0;
    vector<int> v(32, 0);
    for (int i=0; i<32; i++) {
        cout << (x1&t) << " " << (ans&t) << "\n";
        if ((x1&t) == 0 and (ans&t) != 0) {
            v[i] = 1;
        } else if ((x1&t) != 0 and (ans&t) == 0) {
            v[i] = 1;
        }
        t <<= 1;
    }
    for (int i=0; i<32; i++) {
        if (v[i] == 1) {
            x2 += pow(2, i);
        }
    }
    return x2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cout << go(0,2) << "\n";
    
    return 0;
}
