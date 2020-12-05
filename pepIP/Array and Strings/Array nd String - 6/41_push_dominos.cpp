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
        string dominoes = ".L.R...LR..L.."; // L.L.R...LR..L..R // 0 1 
        string str = "L";
        for (int i=0; i<dominoes.size(); i++) {
            str.push_back(dominoes[i]);
        }
        str.push_back('R');
        int i=0, j=1;
        while (j < str.size()) {
            // cout << i << ' ' << j << '\n';
            if (str[i] == 'L' && str[j] == 'R') {
                i = j;
            } else if (str[i] == 'L' && str[j] == 'L') {
                for (int k=i+1; k<j; k++) {
                    str[k] = 'L';
                }
                i = j;
            } else if (str[i] == 'R' && str[j] == 'L') {
                int diff = j-i-1;
                if (diff % 2 == 0) {
                    int fh = diff/2;
                    int k=i+1;
                    while (fh--) {
                        str[k] = 'R';
                        k++;
                    }
                    fh = diff/2;
                    while (fh--) {
                        str[k] = 'L';
                        k++;
                    }
                } else {
                    int fh = diff/2;
                    int k=i+1;
                    while (fh--) {
                        str[k] = 'R';
                        k++;
                    }
                    k++;
                    fh = diff/2;
                    while (fh--) {
                        str[k] = 'L';
                        k++;
                    }
                }
                i = j;
            } else if (str[i] == 'R' && str[j] == 'R') {
                for (int k=i+1; k<j; k++) {
                    str[k] = 'R';
                }
                i =j;
            }
            j++;
        }
        string res;
        for (int i=1; i<str.size(); i++) {
            res.pb(str[i]);
        }
        res.pp();
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
