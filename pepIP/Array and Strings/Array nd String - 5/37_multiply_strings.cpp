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
        string num1 = "999";
        string num2 = "111";
        int n = num1.size();
        int m = num2.size();
        int anssize = num1.size() + num2.size();
        vector<int> ans(anssize, 0);
        for (int j=m-1; j>=0; j--) {
            for (int i=n-1; i>=0; i--) {
                int idx1 = i + j;
                int idx2 = i + j + 1;
                int val = (num1[i]-'0')*(num2[j]-'0') + ans[idx2];
                ans[idx2] = val%10;
                ans[idx1] += val/10;
            }
        }
        string res = "";
        int index;
        for (int i=0; i<anssize; i++) {
            index = i;
            if (ans[i] != 0) {
                break;
            }
        }
        for (int i=index; i<anssize; i++) {
            res.push_back((char)ans[i]+48);
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
