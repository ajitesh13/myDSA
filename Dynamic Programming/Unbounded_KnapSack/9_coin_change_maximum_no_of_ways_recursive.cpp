#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& v, int sum, int n) {
    if (n == 0 && sum == 0) return 1;
    else if (n == 0) return 0;
    else {
        if (v[n-1] <= sum) {
            return coinchange(v, sum-v[n-1], n) + coinchange(v, sum, n-1);
        } else return coinchange(v, sum, n-1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector<int> v = {1,2,3}; int sum = 4; // 4
    vector<int> v = {2,5,3,6}; int sum = 10; // 5
    // vector<int> v = {1,2,3}; int sum = 5; // 5
    int n = v.size();
    cout << coinchange(v, sum, n) << "\n";
    
    return 0;
}
