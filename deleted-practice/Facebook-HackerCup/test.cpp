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

    // string a;
    // cin >> a;
    // string b;
    // cin >> b;
    vector<char> a = {'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'Y'};
    vector<char> b = {'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y'};
    vector<int> res1;
    vector<int> res2;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == 'Y' && b[i+1] == 'Y') {
            res1.push_back(i+1);
            res2.push_back(i);
        }
    }
    for (int i=0; i<(res1.size()-1); i++) {
        if ((res1[i+1] - res1[i]) == 1) {
            res2[i+1] = res2[i];
        }
    }
    for (int i=0; i<res1.size(); i++) {
        cout << res1[i] << " " << res2[i] << endl;
    }


    // string c;
    // cin >> c;
    // string d;
    // cin >> d;
    vector<char> c = {'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'Y'};
    vector<char> d = {'Y', 'Y', 'N', 'Y', 'Y', 'Y', 'N'};
    vector<int> res3;
    vector<int> res4;
    for (int i=0; i<c.size(); i++) {
        if (c[i] == 'Y' && d[i-1] == 'Y') {
            res3.push_back(i-1);
            res4.push_back(i);
        }
    }
    for (int i=(res3.size()-1); i>0; i--) {
        if ((res3[i] - res3[i-1]) == 1) {
            res4[i-1] = res4[i];
        }
    }
    for (int i=0; i<res3.size(); i++) {
        cout << res3[i] << " " << res4[i] << endl;
    }

    return 0;
}
