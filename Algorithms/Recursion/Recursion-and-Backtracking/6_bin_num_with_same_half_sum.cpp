#include <bits/stdc++.h>
using namespace std;

void printbool(vector<int> res) {
    for (int i=0; i<res.size(); i++) {
        cout << res[i];
    }
    cout << '\n';
    return;
}

void store(vector<int> res, int& n) {
    if (n%2 && res.size() == n) {
        int cnt0 = 0, cnt1 = 0;
        for (int i=0; i<(n/2); i++) {
            cnt0 += res[i];
        }
        for (int i=(n/2+1); i<n; i++) {
            cnt1 += res[i];
        }
        if (cnt0 == cnt1) printbool(res);
        return;
    }
    if (!(n%2) && res.size() == n) {
        int cnt0 = 0, cnt1 = 0;
        for (int i=0; i<(n/2); i++) {
            cnt0 += res[i];
        }
        for (int i=(n/2); i<n; i++) {
            cnt1 += res[i];
        }
        if (cnt0 == cnt1) printbool(res);
        return;
    }
    res.push_back(0);
    store(res, n);
    res.pop_back();
    res.push_back(1);
    store(res, n);
    
}

void gen(int n) {
    vector<int> res;
    res.push_back(1);
    store(res, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        gen(n);
    }
    return 0;
}