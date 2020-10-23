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

int op(int num1, int num2, char opr) {
    if (opr == '*') {
        return num1*num2;
    } else {
        return num1 + num2;
    }
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        string expr = "1+2*3+4*5";
        vector<int> operand;
        vector<char> operate;
        for (int i=0; i<expr.size(); i++) {
            if (i % 2 == 0) operand.pb(int(expr[i]) - 48);
            else operate.pb(expr[i]);
        }
        int n = operand.size();

        vector<vector<int>> mindp(n, vector<int> (n, INT_MAX));
        vector<vector<int>> maxdp(n, vector<int> (n, -1));
        
        for (int i=0; i<operand.size(); i++) {
            mindp[i][i] = operand[i];
            maxdp[i][i] = operand[i];
        }
        for (int gap = 1; gap<n; gap++) {
            for (int left = 0; left < n - gap; left++) {
                int right = left + gap;
                for (int i=left; i<right; i++) {
                    mindp[left][right] = min(mindp[left][right], op(mindp[left][i], mindp[i+1][right], operate[i]));
                    maxdp[left][right] = max(maxdp[left][right], op(maxdp[left][i], maxdp[i+1][right], operate[i]));
                }
            }
        }
        cout << maxdp[0][n-1] << ' ' << mindp[0][n-1] << '\n';

        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        // freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
