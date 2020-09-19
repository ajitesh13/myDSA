// return the first occurance of a key in array

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 3, 3, 3, 4, 5};
    int res = INT_MAX;
    int search = 3;
    int lo = 0, hi = v.size()-1;
    while ( lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (v[mid] > search) {
            hi - mid -  1;
        } else if (v[mid] < search) {
            lo = mid + 1;
        } else {
            res = min(res, mid);
            hi = mid - 1;
        }
    }
    cout << res << '\n';
    return 0;
}