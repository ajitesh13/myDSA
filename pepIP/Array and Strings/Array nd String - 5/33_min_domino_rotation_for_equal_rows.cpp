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
        vector<int> A = {2,1,2,4,2,2};
        vector<int> B = {5,2,6,2,3,2};
        cout << A.size() << '\n';
        int num1 = A[0], num2 = B[0], n = A.size();
        int cnt1 = 0, cnt2 = 0, cnt3=0, cnt4=0;
        for (int i=0; i<n; i++) {
            if (cnt1 != INT_MAX) {
                if (A[i] == num1) {}
                else if (B[i] == num1) {
                    cnt1++;
                } else {
                    cnt1 = INT_MAX;
                }
            }
            
            if (cnt2 != INT_MAX) {
                if (B[i] == num2) {}
                else if (A[i] == num2) {
                    cnt2++;
                } else {
                    cnt2 = INT_MAX;
                }
            }
            
            if (cnt3 != INT_MAX) {
                if (A[i] == num2) {} 
                else if (B[i] == num2) {
                    cnt3++;
                } else {
                    cnt3 = INT_MAX;
                }
            }
            
            if (cnt4 != INT_MAX) {
                if (B[i] == num1) {}
                else if (A[i] == num1) {
                    cnt4++;
                } else {
                    cnt4 = INT_MAX;
                }
            }
            
        }
        if (cnt1 == INT_MAX && cnt2 == INT_MAX) {
            cout << -1;
        } else {
            int ans1 = min(cnt1, cnt2);
            int ans2 = min(cnt3, cnt4);
            cout << min(ans1, ans2);
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
