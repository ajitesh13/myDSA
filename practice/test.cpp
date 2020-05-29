// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

int upperbound(int ar[], int p, int r, int val) {
    while (p <= r) {
        int q = (p + r)/2;
        if (a[q] > val) {

        } else {

        }
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[] = { 2, 4, 5, 5, 5, 7 };
    cout << upperbund(ar, 0, 5, 5) << endl;
    
    return 0;
}
