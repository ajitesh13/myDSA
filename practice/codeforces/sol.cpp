// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

int vsum(vector<int> v) {
    int sum = 0;
    for (int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

void solve() {
    int t;
    cin >> t;
    int google_contest_count = 0;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int p = 0, q = 0, cnt = 0;
        while (cnt < k && p < n && q < n) {
            if (a[p] < b[q]) {
                swap(a[p], b[q]);
            }
            p++;
            q++;
            cnt++;
        }
        cout << vsum(a) << '\n';
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
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
