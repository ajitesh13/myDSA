#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v;
    int input;
    for(int i=0; i<n; i++) {
        cin >> input;
        v.push_back(input);
    }
    int count = 0;
    for(int i=0; i<v.size(); i++) {
        count += v[i];
    }
    float res = (float)count/(100*n);
    cout << res*100.00 << setprecision(8)<< endl;
    return 0;
}
