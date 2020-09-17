// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;
const int MAX = 10e6;

// Do it again (Not done till now)

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

double gen(vector<int> v1, vector<int> v2, int lo, int hi, int getl) {
    int tem1, tem2;
    while (lo <= hi) {
        cout << lo << ' ' << hi << '\n';
        int mid1 = lo + (hi - lo)/2;
        int mid2 = getl - mid1;
        if (mid1 < v1.size() && mid2 < v2.size() && mid2 > 0 && v2[mid2-1] >= v1[mid1]) {
            if (mid1 < v1.size()) {
                lo = mid1 + 1;
            }
        } else if (mid1 > 0 && mid2 < v2.size() && mid2 > 0 && v2[mid2-1] >= v1[mid1]) {
            if (mid1 > 0) {
                hi = mid1 - 1;
            }
        } else {
            if (mid1 == v1.size() && mid2 >= 0 && mid2 < v2.size()) {
                tem1 = max(v1[mid1-1], v2[mid2-1]);
                tem2 = v2[mid2];
                cout << 1;
            } else if (mid1 == 0 && mid2 >= 0 && mid2 < v2.size()) {
                tem1 = v2[mid2-1];
                tem2 = min(v1[mid1], v2[mid2]);
                cout << 2;
            } else if (mid2 == v2.size() && mid1 >= 0 && mid1 < v1.size()) {
                tem1 = max(v1[mid1-1], v2[mid2-1]);
                tem2 = v1[mid1];
                cout << 3;
            } else if (mid2 == 0 && mid1 >= 0 && mid1 < v1.size()) {
                tem1 = v1[mid1-1];
                tem2 = min(v1[mid1], v2[mid2]);
                cout << 4;
            } else {
                tem1 = max(v1[mid1-1], v2[mid2-1]);
                tem2 = min(v1[mid1], v2[mid2]);
                cout << 5;
            }
        }
    }

    return ((tem1 + tem2)/2.0);
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v1(n);
        for (int i=0; i<n; i++) {
            cin >> v1[i];
        }
        vector<int> v2(m);
        for (int i=0; i<m; i++) {
            cin >> v2[i];
        }
        double res;
        int getl = (n+m)/2;
        if ((n+m) % 2 == 0) {
            res = gen(v1, v2, 0, v1.size(), getl);
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
