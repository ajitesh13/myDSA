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

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    int s1 = p1.second - p1.first;
    int s2 = p2.second - p2.first;
    if (s1 < s2) {
        return p1 < p2;
    }
    //  else if (s2 > s1) {
    //     return p2 < p1;
    // }
    return true;
    //  else {
    //     if (p1.first < p2.first) {
    //         return p1 < p2;
    //     } else {
    //         return p2 < p1;
    //     }
    // }
}

void solve() {
    int t = 1;
    // cin >> t;
    int google_contest_count = 0;
    while(t--) {
        deque<pair<int,int>> dq;
        dq.pb(mp(4,6));
        dq.pb(mp(1,2));
        dq.pb(mp(2,2));
        dq.pb(mp(4,4));
        dq.pb(mp(6,6));
        sort(dq.begin(), dq.end(), cmp);
        for (int i=0; i<dq.size(); i++) {
            cout << dq[i].first << " " << dq[i].second << '\n';
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
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
