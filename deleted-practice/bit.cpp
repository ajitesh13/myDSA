#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> v;
    string tempstr;
    for(int i=0;i<n; i++) {
        cin >> tempstr;
        v.push_back(tempstr);
    }
    int res = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].find("++") != -1) {
            res += 1;
        } else if(v[i].find("--") != -1) {
            res -= 1;
        }
    }
    cout << res << endl;
    return 0;
}
