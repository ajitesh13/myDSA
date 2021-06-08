#include <bits/stdc++.h>
using namespace std;

int countsubsetsum(vector<int>& v, int n, int sum) {
    if (n == 0 and sum == 0) return 1;
    else if (n == 0) return 0;
    else {
        if (v[n-1] <= sum) return countsubsetsum(v, n-1, sum-v[n-1]) + countsubsetsum(v, n-1, sum);
        else return countsubsetsum(v, n-1, sum);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {0,0,0,0,0,0,0,0,1};
    int n = v.size();
    int sum = 1;
    cout << countsubsetsum(v, n, sum) << "\n";
    
    return 0;
}
