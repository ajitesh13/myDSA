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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m));
        unordered_map<int,vector<int>> ump;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> v[i][j];
                if (ump.find(j-i) == ump.end()) {
                    ump.insert({j-i, {v[i][j]}});
                } else {
                    vector<int>& v1 = ump.find(j-i)->second;
                    v1.pb(v[i][j]);
                }
            }
        }
        for (auto it=ump.begin(); it!=ump.end(); it++) {
            cout << it->first << ": ";
            for (int i=0; i<it->second.size(); i++) {
                cout << it->second[i] << ' ';
            }
            cout << '\n';
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
