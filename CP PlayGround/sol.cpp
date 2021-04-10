#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {1,0,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0};
    int lmax = 0, omax = 0;
    if (v[0] == 0) lmax++;
    omax = max(lmax, omax);
    for (int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;
    cout << omax << " ";
    for (int i=1; i<v.size(); i++) {
        if (v[i] == 0) {
            if (v[i-1] == 0) {
                lmax++;
                omax = max(omax,lmax);
            } else {
                lmax = 1;
                omax = max(omax, lmax);
            }
        }
        cout << omax << " ";
    }
    cout << endl;
    // cout << omax << "\n";

    
    return 0;
}
