#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void go(vector<int> v, int n, vector<int> t) {
    for (int i=0; i<n; i++) {
        t.push_back(v[i]);
        go(v, n, t);
        t.pop_back();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1,2,3};
    go(v, v.size(), {});
    
    return 0;
}
