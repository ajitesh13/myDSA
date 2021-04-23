#include <bits/stdc++.h>
using namespace std;

// normal binary search

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    vector<int> v = {1,2,3,4,5};
    int x = 5;

    int l = 0, r = n-1, index;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (v[m] == x) {
            index = m;
            break;
        } else if (v[m] < x) {
            l = m + 1;
        } else if (v[m] > x) {
            r = m - 1;
        }
    }
    cout << index << "\n";
    
    return 0;
}
