#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    int a, b, c;
    int d = 0;
    int e = 0;
    int f = 0;
    while(n--) {
        cin >> a >> b >> c;
        d+=a; e+=b; f+=c;
    }
    if(d==0 && e==0 && f==0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
