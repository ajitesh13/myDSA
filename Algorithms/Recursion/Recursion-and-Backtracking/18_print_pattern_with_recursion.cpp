// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

// A positive integer is given, print a sequence, such that A[i+1] = A[i] - 5 if A[i] > 0 else
// retreat in the reverse order, printing the number along the way, till the point where 
// we get our original number(A[0]) back. (Give a recursive solution)

// Example :- 
// Input: 
// 2
// 16
// 18
// Output:
// 16 11 6 1 -4 1 6 11 16 
// 18 13 8 3 -2 3 8 13 18 



#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pp pop_back
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void gen(int n, int k) {
    if (k > 0) {
        cout << k << " ";
        gen(n, k-5);
        cout << k << " ";
        if (k == n) {
            return;
        }
    } else {
        cout << k << " ";
    }
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        gen(n, n);
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    return 0;
}
