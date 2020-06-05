// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;
int dp[INT_MAX] = {-1};

int fib(int n) {
    dp[1] = 0;
    dp[2] = 1;
    if (n == 1 || n == 2) {
        return dp[n];
    } else {
        if (dp[n] == -1) {
            dp[n] = dp[n-1] + dp[n-2];
            return dp[n];
        } else {
            return dp[n];
        }
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cout << fib(n) << endl;
    
    return 0;
}
