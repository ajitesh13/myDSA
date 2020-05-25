// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
// #define int long long
#define endl "\n"
using namespace std;

bool vw(pair<int,int> p1, pair<int,int> p2) {
    double r1 = (double)p1.first/p1.second;
    double r2 = (double)p2.first/p2.second;
    return( r1 > r2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> v;
    vector<pair<int,int>>::iterator it;
    int f, s;
    for (int i=0; i<n; i++) {
        cin >> f;
        cin >> s;
        v.push_back(make_pair(f, s));
    }
    int W;
    cin >> W;
    int x, resv = 0, resw = 0;
    double t;
    sort(v.begin(), v.end(), vw);
    for (it = v.begin(); it != v.end(); it++) {
        if ((*it).second <= (W-resw)) {
            resw += (*it).second;
            resv += (*it).first;
        } else {
            x = W-resw;
            t = (double)x/((*it).second);
            resv += t*(*it).second;
            resw += t*(*it).first;
        }
    }
    cout << resv << " " << resw << endl;
    return 0;
}
