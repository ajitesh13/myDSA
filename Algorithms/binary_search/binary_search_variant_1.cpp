// normal binary search approach

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,4,7,9,15,17,18};
    int search = 18;
    int lo = 0, hi = v.size()-1, res;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (v[mid] < search) {
            lo = mid + 1;
        } else if (v[mid] > search) {
            hi = mid - 1;
        } else {
            res = mid;
            break;
        }
    }
    cout << res << '\n';
    return 0;
}