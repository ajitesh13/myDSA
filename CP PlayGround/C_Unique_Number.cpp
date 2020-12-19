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
    int t;
    cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int x;
        cin >> x;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        if (x > 45) {
            cout << -1 << '\n';
        } else if (x % 10 == x) {
            cout << x << '\n';
        } else {
            unordered_set<int> st;
            for (int i=v.size()-1; i>=0; i--) {
                if (st.find(x-i) == st.end() && x-i != i) {
                    x -= i;
                    st.insert(i);
                    if (x % 10 == x) {
                        st.insert(x);
                        break;
                    }
                }
            }
            vector<int> res;
            for (auto it=st.begin(); it!=st.end(); it++) {
                res.pb(*it);
            }
            sort(res.begin(), res.end());
            for (int i=0; i<res.size(); i++) {
                cout << res[i];
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
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
