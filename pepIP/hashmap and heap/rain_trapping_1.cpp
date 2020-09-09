// rain trapping - I problem in O(2n) space


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
    // int google_contest_count = 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
        vector<int> leftmx(n, -1);
        if (n > 1) {
            vector<int> leftmax(n, -1);
            vector<int> rightmax(n, -1);
            leftmax[0] = 0;
            rightmax[n-1] = 0;

            for (int i=1; i<n; i++) {
                leftmax[i] = max(leftmax[i-1], height[i-1]);
            }

            for (int i=n-2; i>=0; i--) {
                rightmax[i] = max(rightmax[i+1], height[i+1]);
            }

            int res = 0;

            for (int i=0; i<n; i++) {
                int val = min(leftmax[i], rightmax[i]) - height[i];
                if (val < 1) {
                    continue;
                }
                res += val;
            }

            return res;
        } else {
            return 0;
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
