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
    
    int na, nb;
    cin >> na >> nb;
    vector<int> a(na);
    vector<int> b(nb);
    for (int i=0; i<na; i++) {
        cin >> a[i];
    }
    for (int i=0; i<nb; i++) {
        cin >> b[i];
    }
    int res = 0;
    vector<int>::iterator it;
    for (int i=0; i<nb; i++) {
        it = upper_bound(a.begin(), a.end(), b[i]);
        cout << (it - a.begin());
    }
    cout << endl;

    return 0;
}
