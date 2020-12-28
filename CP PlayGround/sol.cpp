#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
#define f first
#define s second
using namespace std;

// min-heap
class comp{
public:
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

// sort pair
bool comp1(pair<int,int> a, pair<int,int> b) {
    return(a.second < b.second);
}

void solve() {
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i=0; i<n; i++) {
            cin >> r[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i=0; i<m; i++) {
            cin >> b[i];
        }
        vector<int> rprefix(n, 0);
        vector<int> bprefix(m, 0);
        rprefix[0] = r[0];
        bprefix[0] = b[0];
        int mx1 = INT32_MIN, mx2 = INT32_MIN;
        for (int i=1; i<n; i++) {
            rprefix[i] = rprefix[i-1] + r[i];
            mx1 = max(mx1, rprefix[i]);
        }
        for (int i=1; i<m; i++) {
            bprefix[i] = bprefix[i-1] + b[i];
            mx2 = max(mx2, bprefix[i]);
        }
        mx1 = max(mx1, rprefix[0]);
        mx2 = max(mx2, bprefix[0]);
        mx1 = max(mx1, 0);
        mx2 = max(mx2, 0);
        int res;
        res = max(0, mx1+mx2);
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
    
    return 0;
}
