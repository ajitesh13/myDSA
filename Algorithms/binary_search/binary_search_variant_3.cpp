// find the last occurance of the key 

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 3, 3, 3, 4, 5};
    int res = -1;
    int search = 3;
    int lo = 0, hi = v.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi -lo) / 2;
        if (v[mid] < search) {
            hi = mid - 1;
        } else if (v[mid] > search) {
            lo = mid + 1;
        } else {
            res = max(res, mid);
            lo = mid + 1;
        }
    }
    cout << res << '\n';
    return 0;
}