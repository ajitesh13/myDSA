// mcm without DP

#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int ar[], int i, int j) {
    if (i == j) {
        return 0;
    }
    int k;
    int min = INT_MAX;
    int count;
    for (k = 0; k < j; k++) {
        count = MatrixChainOrder(p, i, k) +
                MatrixChainOrder(p, k + 1, j) +
                p[i-1] * p[k]*p[j];
        if (count < min) {
            min = count;
        }
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ar={1,2,3,4,3};
    cout << MatrixChainOrder(ar, 1, n-1) << '\n';
    
    return 0;
}
