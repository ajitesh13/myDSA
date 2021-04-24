/* Binary Seach on real numbers 
*  Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B 
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

bool good(double x) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += floor((double)v[i]/x);
    }
    return sum >= k;
}

void best() {
    int __ = 1;
    // cin >> __;
    while(__--) {
        cin >> n >> k;
        v.resize(n);
        for (int i=0; i<n; i++) cin >> v[i];
        double l = 0; // good 
        double r = 10e8; // bad
        for (int i=1; i<=100; i++) {
            double m = l + (r-l)/2;
            if (good(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << setprecision(16);
        cout << r << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
    #endif
    
    best();
    
    return 0;
}

