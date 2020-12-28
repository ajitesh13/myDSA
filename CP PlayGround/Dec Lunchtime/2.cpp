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
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "Yes" << '\n';
            continue;
        }
        int a1 = 0, a0 = 0, b1 = 0, b0 = 0;
        vector<int> aindex;
        vector<int> bindex;
        for (int i=0; i<n; i++) {
            if (a[i] == '1') {
                a1++;
                aindex.pb(i);
            } else {
                a0++;
            }
            if (b[i] == '1') {
                bindex.pb(i);
                b1++;
            } else {
                b0++;
            }
        }
        if (a1 == b1 && a0 == b0) {
            if (a1 != 0 && a0 != 0) {
                sort(aindex.begin(), aindex.end());
                sort(bindex.begin(), bindex.end());
                if (aindex[aindex.size()-1] <= bindex[0]) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            } else {
                cout << "Yes" << '\n';
            }
            
        } else {
            cout << "No" << '\n';
        }

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
