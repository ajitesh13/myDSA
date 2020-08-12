// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
#define MAX 10e5
//#define MAX 10e4
using namespace std;
int res = 0;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void isPal(string ns, int l, int r) {
    if (r-l < 1) {
        return;
    } else {
        if (ns[l] != ns[r]) {
            res++;
            return;
        }
        isPal(ns, l+1, r-1);
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("in", "r", stdin);
    // #endif
    
    int t;
    cin >> t;
    while (t--) {
        res = 0;
        int n;
        cin >> n;
        string ns = to_string(n);
        isPal(ns, 0, ns.size()-1);
        cout << (res ? "NO" : "YES") << endl;
    }
    
    // cerr << "\n\n**ET : " << tick() << "**\n";
    return 0;
}
