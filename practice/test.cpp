#include <bits/stdc++.h>
using namespace std;

int c[][2];

void ifit(int x, int k) {
    for(int i=0; i<max; i++) {
        for(int j=0; j<2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int x, k;
        // cin >> x >> k;
        ifit(5, 5);
    }

    return 0;
}
