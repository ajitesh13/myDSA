#include <bits/stdc++.h>
using namespace std;

// first write the base base condition of sum = 0 then made the condition of n == 0

bool subsetsum(vector<int> v, int n, int sum) {
    if (sum == 0) return true;
    else if (n == 0) return false; 
    else {
        if (v[n-1] <= sum) return subsetsum(v, n-1, sum-v[n-1]) || subsetsum(v, n-1, sum);
        else return subsetsum(v, n-1, sum);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {3, 34, 4, 12, 5, 2};
    int n = v.size();
    int sum = 37;
    cout << subsetsum(v, n, sum) << "\n";
    
    return 0;
}
