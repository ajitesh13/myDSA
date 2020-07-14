// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

int calno (int ques) {
    int noques = 0;
    while (ques % 2 == 0) {
        ques /= 2;
        noques++;
    }
    return noques;
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int tc = 1;
    int t;
    cin >> t;
    while (t--) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n, cntr = 0, far = 0, res;
        cin >> n;
        if (n % 2 != 0) {
            res = n / 2;
        } else {
            int targetcalno = calno(n);
            int base = pow(2, targetcalno+1);
            if (base > n) {
                res = 0;
            } else {
                for (int i = n-1; i >= 0; i--) {
                    if (calno(i) > targetcalno) {
                        far = i;
                        break;
                    }
                }
                res = far / base;
            }
        }
        cout << res << endl;
        
        // cout << "Case #" << tc << ": " <<<< "\n"; tc++;
    }
    
    return 0;
}