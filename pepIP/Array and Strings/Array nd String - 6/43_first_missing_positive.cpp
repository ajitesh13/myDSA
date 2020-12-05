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


void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<int> nums = {0,2,2,1,1};
        int i=0;
        while (i < nums.size()) {
            cout << i << '\n';
            if (nums[i] < 1 || nums[i] > nums.size() || nums[i] == i+1) {
                i++;
                continue;
            } else {
                int pos = nums[i]-1;
                if (nums[pos] != nums[i]) {
                    swap(nums[i], nums[pos]);
                } else {
                    i++;
                }
            }
        }
        int cnt = 0;
        int res = nums.size()+1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) {
                res = i+1;
                cnt++;
                break;
            }
        }
        if (cnt == 0) {
            cout << res << '\n';
        } else {
            cout << res << '\n';
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
