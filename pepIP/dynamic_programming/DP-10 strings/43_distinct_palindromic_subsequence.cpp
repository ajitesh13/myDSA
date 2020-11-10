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
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        string text1 = "abac", text2 = "cab";
        vector<vector<int>> dp(text2.size(), vector<int> (text1.size(), 0));
        string text3 = "";
        if (text1[0] == text2[0]) {
            dp[0][0] = 1;
        }
        for (int j=1; j<text1.size(); j++) {
            if (text2[0] == text1[j]) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = max(dp[0][j], dp[0][j-1]);
            }
        }
        for (int i=1; i<text2.size(); i++) {
            if (text2[i] == text1[0]) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = max(dp[i][0], dp[i-1][0]);
            }
        }
        for (int i=1; i<text2.size(); i++) {
            for (int j=1; j<text1.size(); j++) {
                if (text1[j] == text2[i]) {
                    dp[i][j] = 1 + max(dp[i-1][j-1], dp[i-1][j-1]);
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i=text2.size()-1, j=text1.size()-1;
        while (i >= 0 && j >= 0) {
            if (text2[i] == text1[j]) {
                text3.pb(text1[j]);
                i--;
                j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
        cout << dp[text2.size()-1][text1.size()-1] << '\n';
        reverse(text3.begin(), text3.end());
        string res = "";
        int i1 = 0, j1 = 0, k1 = 0;
        while (true) {
            if (i1 == text1.size() && j1 < text2.size()) {
                for (int k = j1+1; k < text2.size(); k++) {
                    res.pb(text2[j1]);
                }
                j1++;
            } 
            if (j1 == text2.size() && i1 < text1.size()) {
                for (int k = i1+1; k < text1.size(); k++) {
                    res.pb(text1[i1]);
                }
                i1++;
            }
            if (i1 == text1.size() && j1 == text2.size()) break;
            if (text1[i1] == text3[k1]) {
                if (text2[j1] == text3[k1]) {
                    res.pb(text1[i1]); i1++; j1++; k1++;
                } else {
                    res.pb(text2[j1]); j1++;
                }
            } else {
                res.pb(text1[i1]); i1++;
            }
        }
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
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
