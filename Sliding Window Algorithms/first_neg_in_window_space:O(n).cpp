#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> A = {12, -1, -7, 8, -15, 30, 16, 28};
    int K = 3;
    int N = A.size();
    vector<long long> neg(N);
    if (A[N-1] >= 0) neg[N-1] = -1;
    else neg[N-1] = N-1;
    for (int i=(N-2); i>=0; i--) {
        if (A[i] < 0) {
            neg[i] = i;
        } else neg[i] = neg[i+1];
    }
    int i = 0, j = K-1;
    vector<long long> res;
    while (j < N) {
        if (neg[i] <= j && neg[i] != -1) res.push_back(A[neg[i]]);
        else res.push_back(0);
        i++;
        j++;
        if (j == N) break;
    }
    for (int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << "\n";
    
    return 0;
}
