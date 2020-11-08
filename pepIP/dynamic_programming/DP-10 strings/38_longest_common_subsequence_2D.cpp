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
        string text1 = "bsbininm", text2 = "jmjkbkjkv";
        vector<vector<int>> dp(text2.size(), vector<int> (text1.size(), 0));
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
        for (int i=0; i<text2.size(); i++) {
            for (int j=0; j<text1.size(); j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << dp[text2.size()-1][text1.size()-1] << '\n';

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
