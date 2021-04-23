#include <bits/stdc++.h>
using namespace std;

// min i for which a[i] >= x (closest element to the right)

/* 
* l = -1, r = n
* invariants will be:
* a[l] < x 
* a[r] >= x 
*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 9;
    vector<int> v = {1,2,3,4,5,5,5,5,5};
    int x = 5;

    int l = -1; // a[l] < x
    int r = n; // a[r] >= x
    while (r > l+1) {
        int m = l + (r-l)/2;
        if (v[m] >= x) { // make the if same as one of the invariant and just add the else
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";
    
    return 0;
}