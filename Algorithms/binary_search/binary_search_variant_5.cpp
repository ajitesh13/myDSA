// last occurance of the element less than key 

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 3, 4, 5};
    int search = 4;
    int res;
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (v[mid] > search) {
            hi = mid - 1;
        } else if (v[mid] < search) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << '\n';
    return 0;
}