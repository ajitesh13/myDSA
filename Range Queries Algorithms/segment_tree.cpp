#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &t[n+i]);
    build();
    for (int i=n; i<2*n; i++) {
        cout << t[i] << ' ';
    }
    modify(2, t[n+2]+3); // incrementing the 2nd index by 3 and 0 based indexing
    cout << endl;
    for (int i=n; i<2*n; i++) {
        cout << t[i] << ' ';
    }
    cout << endl;
    cout << query(3,5) << '\n'; // sum on interval [l, r) and 0 based indexing
    return 0;
}
