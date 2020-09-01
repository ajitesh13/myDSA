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
    int t;
    cin >> t;
    int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<tuple<int,int,int>> vt;
        for (int i=0; i<n; i++) {
            int tf = (0-v[i]);
            unordered_map<int,int> ump;
            for (int j=i+1; j<n; j++) {
                int tar = tf - v[j];
                if (ump.find(tar) == ump.end()) {
                    ump.insert(mp(v[j], tar));
                } else {
                    vt.pb(mt(v[j], tar, v[i]));
                }
            }
        }
        for (int i=0; i<vt.size(); i++) {
            cout << get<0>(vt[i]) << ' ' << get<1>(vt[i]) << ' ' << get<2>(vt[i]) << '\n';
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
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
