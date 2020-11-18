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

vector<int> LPS(string st) {
    vector<int> lps(st.size());
    int i = 1, len = 0;
    while (i < st.size()) {
        if (st[i] == st[len]) {
            lps[i] = len + 1;
            i++;
            len = lps[i-1];
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pat) {
    string newstr = pat + '#' + text;
    vector<int> lps = LPS(newstr);
    vector<int> res;
    for (int i=0; i<lps.size(); i++) {
        if (lps[i] == pat.size()) {
            res.pb(i - pat.size() - 1);
        }
    }
    return res;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        string text = "aabaabaab";
        string pat = "aab";
        vector<int> res = KMP(text, pat);
        for (int i=0; i<res.size(); i++) {
            cout << res[i] << " ";
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
