#include <bits/stdc++.h>
using namespace std;

vector<int> fact(int n) {
    vector<int> res;
    for (int i=2; i*i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> res = fact(36);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}
