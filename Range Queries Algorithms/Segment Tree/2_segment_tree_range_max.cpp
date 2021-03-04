#include <bits/stdc++.h>
using namespace std;
vector<int> t;

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int retmax(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -1;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(retmax(v*2, tl, tm, l, min(r, tm)),retmax(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    t.assign(4*n, INT32_MIN);
    build(v, 1, 0, n-1);
    int l = 1, r = 3;
    cout << retmax(1,0,n-1,l-1,r-1) << "\n";
    update(1,0,n-1,2,3);
    cout << retmax(1,0,n-1,l-1,r-1) << "\n";

    
    return 0;
}
