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

// bottom - up approach

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<vector<int>> grid = {
            {1, 3, 1}, {1, 5, 1}, {4, 2, 1}
        };
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dp(row, vector<int> (col));
        dp[row-1][col-1] = grid[row-1][col-1];
        for (int i=col-2; i>=0; i--) {
            dp[row-1][i] = dp[row-1][i+1] + grid[row-1][i];
        }
        for (int i=row-2; i>=0; i--) {
            dp[i][col-1] = dp[i+1][col-1] + grid[i][col-1];
        }
        for (int i=row-2; i>=0; i--) {
            for (int j=col-2; j>=0; j--) {
                dp[i][j] = min(dp[i][j+1]+ grid[i][j], dp[i+1][j]+ grid[i][j]);
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                cout << dp[i][j] << ' ';
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
