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

int countdigit(long long n) { 
    return floor(log10(n) + 1); 
} 

int num(char c) {
    return (int)c-48;
}

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        int n = 1999999999;
        string s = to_string(n);
        int cnt = 0;
        for (int i=s.size()-2; i>=0; i--) {
            if (num(s[i]) < num(s[i+1])) {
                int ng;
                for (int j=i+1; j<s.size(); j++) {
                    if (s[j] > s[i]) {
                        ng = j;
                    }
                }
                swap(s[i], s[ng]);
                sort(s.begin()+i+1, s.end());
                cnt++;
                break;
            } else {
                continue;
            }
        }

            stringstream res(s);
            long long x = 0;
            res >> x;
            if (x > INT32_MAX) {
                // return -1;
                cout << -1 << '\n';
            } else {
                if (cnt == 0) {
                    cout << -1 << '\n';
                } else {
                    cout << x << '\n';
                }
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
