// Number of rotations in circular array
//     a. Given a circularly sorted array, find the extent of rotation of the array. Assume no duplicates and anti-clockwise rotation
//     b. Input – [8, 9, 10, 2, 5, 7]
//     c. Output – Rotation extent = 3


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    int flag = 0;
    for(int i=0; i<n-1; i++) {
        if(!(a[i] < a[i+1])) {
            flag = i;
        }
    }
    // cout << flag << endl;
    cout << n-flag-1 << endl;
    return 0;
}