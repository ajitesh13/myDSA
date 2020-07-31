// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int l = 0, r = 0;
    int max = -1, count = v[0];
    while (l < n && r < n) {
        if (count < m) {
            r++;
            if (r > n-1) {
                break;
            }
            count += v[r];
            if (count > max && count <= m) {
                max = count;
            }
        } else if (count > n) {
            count -= v[l];
            l++;
            if (l > n-1) {
                break;
            }
            if (count > max && count <= m) {
                max = count;
            }
        } else {
            break;
        }
    }
    cout << max << endl;

    return 0;
}
