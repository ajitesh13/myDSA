#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> v, int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}



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
    int m;
    cin >> m;
    vector<int> b;
    for(int i=0; i<m; i++) {
        cin >> input;
        b.push_back(input);
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<m; i++) {
        int it = bs(v, 0, v.size(), b[i]);
        cout << it << endl;
        sum1 += abs(it+1);
        cout << sum1 << endl;
        // sum2 += abs(it-n);
    }
    cout << sum1 << " " << sum2;
    return 0;
}
