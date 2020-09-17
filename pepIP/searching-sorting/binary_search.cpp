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

void Binary_Search(vector<int>& v, int l, int r, int search) {
    if (l < r) {
        int mid = l + (r - l)/2;
        if (search > v[mid]) {
            Binary_Search(v, mid+1, r, search);
        } else if (search < v[mid]) {
            Binary_Search(v, l, mid-1, search);
        } else {
            cout << mid << '\n';
        }
    } else if ( l == r) {
        cout << l << '\n';
    }
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        int search;
        cin >> search;
        Binary_Search(v, 0, n-1, search);
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
