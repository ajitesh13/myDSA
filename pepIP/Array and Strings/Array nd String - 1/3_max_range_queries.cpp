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

void solve() {

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int> (2));
        int size = 0;
        for (int i=0; i<n; i++) {
            cin >> v[i][0] >> v[i][1];
            size = max(size, v[i][1]);
        }
        size++;
        int countk = 0;
        vector<int> prefixsum(size, 0);
        for (int i=0; i<n; i++) {
            prefixsum[v[i][0]] += 1;
            if (v[i][1] + 1 < size) {
                prefixsum[v[i][1] + 1] += -1;
            }
        }
        vector<int> prefixcount(size, 0);
        vector<int> prefixcount1(size, 0);
        if (prefixsum[0] == k) prefixcount[0] = 1;
        if (prefixsum[0] == k+1) prefixcount1[0] = 1;
        for (int i=1; i<size; i++) {
            prefixsum[i] = prefixsum[i-1] + prefixsum[i];
            if (prefixsum[i] == k) {
                countk++;
                prefixcount[i] = prefixcount[i-1] + 1;
            } else {
                prefixcount[i] = prefixcount[i-1];
            } 
            if (prefixsum[i] == k+1) {
                prefixcount1[i] = prefixcount1[i-1] + 1;
            } else {
                prefixcount1[i] = prefixcount1[i-1];
            }
        }
        int res = 0;
        for (int i=0; i<n; i++) {
            int lim1 = v[i][0];
            int lim2 = v[i][1];
            int loss = prefixcount[v[i][1]] - prefixcount[v[i][0]-1];
            int gain = prefixcount1[v[i][1]] - prefixcount1[v[i][0]-1];
            res = max(res, countk - loss + gain);
        }
        cout << res << '\n';
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
