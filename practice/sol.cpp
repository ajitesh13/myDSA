// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
// #define int long long
#define endl "\n" 
using namespace std;
int adjm[10001][10001];

// int main() {
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i=0; i<2*m; i++) {
        cin >> a >> b;
        adjm[a-1][b-1] = 1;
        adjm[b-1][a-1] = 1;
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (adjm[a-1][b-1] && adjm[b-1][a-1]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    return 0;
}
