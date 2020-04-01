#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int storei;
    int storej;
    
    int ar[5][5] = {0};
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> ar[i][j];
            if(ar[i][j] == 1) {
                storei = i;
                storej = j;
                break;
            }
        }
    }
    storei = abs(2-storei);
    storej = abs(2-storej);
    cout << storei+storej << endl;
    return 0;
}
