#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 81, x = 3;
    int cnt = 0;
    while (n%x == 0) {
        cnt++;
        n /= x;
    }
    cout << cnt << '\n';
    
    return 0;
}
