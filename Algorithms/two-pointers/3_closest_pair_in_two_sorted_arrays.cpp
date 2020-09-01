// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pp pop_back
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        } 
        int x;
        cin >> x;
        vector<int> res(n+n);
        vector<bool> check(n+n);
        int p = 0, q = 0, r = 0;
        while (p < n && q < n) {
            if (a[p] <= b[q]) {
                res[r] = a[p];
                check[r] = true;
                r++;
                p++;
            } else {
                res[r] = b[q];
                check[r] = false;
                r++;
                q++;
            }
        }
        while (p < n) {
            res[r] = a[p];
            check[r] = true;
            r++;
            p++;
        }
        while (q < n) {
            res[r] = b[q];
            check[r] = false;
            r++;
            q++;
        }
        // for (int z: res) {
        //     cout << z << ' ';
        // }
        p = 0, q = 2*n - 1;
        int resmin = res[p] + res[q];
        pair<int,int> minp = mp(res[p], res[q]);
        while (p < q) {
            if (res[p] + res[q] > x) {
                q--;
                int sum1 = res[p] + res[q];
                if (sum1 < x && sum1 > resmin && check[p] != check[q]) {
                    resmin = sum1;
                    minp = mp(res[p], res[q]);
                }
            } else if (res[p] + res[q] < x) {
                p++;
                int sum1 = res[p] + res[q];
                if (sum1 < x && sum1 > resmin && check[p] != check[q]) {
                    resmin = sum1;
                    minp = mp(res[p], res[q]);
                }
            }
        }
        cout << minp.first << ' ' << minp.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
