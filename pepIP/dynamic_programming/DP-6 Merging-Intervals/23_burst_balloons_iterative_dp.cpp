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

int dp[500][500] = {0};
int getMax(vector<int> nums1, int left, int right) {
    for (int gap = 2; gap < nums1.size(); gap++) {
        for (int left = 0; left < nums1.size() - gap; left++) {
            int right = left + gap;
            for (int i = left+1; i < right; i++) {
                dp[left][right] = max(dp[left][right], dp[left][i] + nums1[left]*nums1[i]*nums1[right] + dp[i][right]);
            }
        }
    }
    return dp[left][right];
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<int> nums = {3, 1, 5, 8};
        vector<int> nums1;
        nums1.pb(1);
        for (int i=0; i<nums.size(); i++) {
            nums1.pb(nums[i]);
        }
        nums1.pb(1);
        int left = 0, right = nums1.size()-1;
        cout << getMax(nums1, left, right) << ' ';
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
