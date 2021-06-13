#include <bits/stdc++.h>
using namespace std;

int solve(int e, int f) {
    if (f == 0 or f == 1) {
        return f;
    }
    if (e == 1) {
        return f;
    }
    int mn = INT32_MAX;
    for (int k=1; k<=f; k++) {
        int tempans = 1 + max(solve(e-1, k-1), solve(e, f-k));
        mn = min(mn, tempans);
    }
    return mn;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int e = 3, f = 5;
    // int e = 2, f = 10;
    int e = 2, f = 36;
    cout << solve(e, f) << "\n";
    
    return 0;
}
