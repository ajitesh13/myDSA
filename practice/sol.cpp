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
        ll n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        } else if (n == 2) {
            cout << m << '\n';
            continue;
        } else if (n == 3) {
            cout << 2*m << '\n';
            continue;
        } 
        ll p = n/2;
        vector<ll> v;
        for (ll i=1; i<p; i++) {
            m--;
            v.pb(1);
        }
        v.pb(m);
        ll sum = 0;
        for (ll i=0; i<v.size(); i++) {
            sum += v[i];
        }
        if (n % 2 != 0) {
            cout << 2*sum << '\n';
        } else {
            cout << 2*sum - 1 << '\n';
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
