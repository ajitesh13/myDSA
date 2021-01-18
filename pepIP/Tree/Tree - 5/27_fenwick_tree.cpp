#include <bits/stdc++.h>
#define int long long int
using namespace std;

vector<int> fenwick;
vector<int> v;

int sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= (i & -i);
    }
    return sum;
}

void update(int i, int delta) {
    while (i <= v.size()) {
        fenwick[i] += delta;
        i += (i & -i);
    }
}

int rangesum(int l, int r) {
    return sum(r)-sum(l-1);
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out1", "w", stdout);
    #endif

    int n;
    cin >> n;
    v.assign(n+1, 0);
    fenwick.assign(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        update(i, v[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        if (ch == 'q') {
            cout << rangesum(l, r) << '\n';
        } else update(l, r);
    }

    return 0;
}
