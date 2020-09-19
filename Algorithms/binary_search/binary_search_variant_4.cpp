// first occurance of least element grater than key in array

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 5};
    int search = 2;
    int res;
    int lo = 0, hi = v.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] > search) {
            res = mid;
            hi = mid - 1;
        } else if (v[mid] < search) {
            lo = mid + 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << '\n';
    return 0;
}