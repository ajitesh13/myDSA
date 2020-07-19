// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;
int n, e;
int ar[1000][1000];

void initialise() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ar[i][j] = false;
        }
    }
}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> e;
    initialise();
    int x, y;
    for (int i=0; i<e; i++) {
        cin >> x >> y;
        ar[x-1][y-1] = true;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << ar[i][j] << " ";
        }
        cout << "\n";
    }



    
    return 0;
}
