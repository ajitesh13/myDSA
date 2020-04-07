#include <bits/stdc++.h>
using namespace std;

int bs(int v[], int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[3] = {3, 1, 2};
    cout << bs(v, 0, 2, 3);

    return 0;
}
