// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

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
    vector<ll> v = {0};
    ll i = 1, k = 0;
    while (i < 2*1000000009LL) {
        v.pb(i);
        k++;
        i += k;
    }
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll index = 0, diff = 0;
        ll i;
        ll lim = min(2*1000000009LL, n*(n-1)/2);
        for (i=1; i<=lim; i++) {
            if (i >= v.size()) {
                i = v.size()-1;
            }
            if (k < v[i]) {
                index = i-1;
                diff = k - v[index];
                break;
            } else if (k == v[i]) {
                index = i;
                diff = k - v[index];
            }
            
           
        }
        string str(n, 'a');
        ll firstb = n - index - 1;
        ll secondb = n - diff - 1;
        str[firstb] = 'b';
        str[secondb] = 'b';
        cout << str << '\n';
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
