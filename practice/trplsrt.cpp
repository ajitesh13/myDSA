// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> res;

int solve(vector<int> v) {
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    vector<int> b;
    for (unsigned i=0; i<v.size(); i++) {
        if (temp[i] != v[i]) {
            b.push_back(v[i]);
        }
    }
    int big = -1;
    int index = 0;
    for (unsigned i=0; i<b.size(); i++) {
        if (b[i] > big ) {
            big = b[i];
            index = i;
        }
    }
    if (b.size() == 0) {
        return(1);
    } else if (b.size() < 3) {
        return(0);
    } else if (b.size() == 3) {
        if (big != b[0]) {
            sort(b.begin(), b.end());
            for (unsigned i=0; i<b.size(); i++) {
                res.push_back(b[i]);
            }
            return(1);
        } else {
            int two = 2;
            sort(b.begin(), b.end());
            while (two--) {
                for (unsigned i=0; i<b.size(); i++) {
                    res.push_back(b[i]);
                }
            }
            return(1);
        }
    } else {
        if (big != b[0]) {
            vector<int> c(b.size()-1);
            for (unsigned i=0; i<(b.size()-1); i++) {
                c[i] = b[i];
            }
            c[0] = b[b.size()-1];
            c[index] = b[0];
            vector<int> d;
            d.push_back(b[0]);
            d.push_back(b[b.size()-1]);
            d.push_back(b[index]);
            sort(d.begin(), d.end());
            for(int i=0; i<d.size(); i++) {
                res.push_back(d[i]);
            }
            solve(c);
        } else {
            vector<int> c(b.size()-1);
            for (unsigned i=0; i<(b.size()-1); i++) {
                c[i] = b[i];
            }
            c[0] = b[1];
            c[1] = b[b.size()-1];
            vector<int> d;
            d.push_back(b[0]);
            d.push_back(b[1]);
            d.push_back(b[b.size()-1]);
            sort(d.begin(), d.end());
            int two = 2;
            while (two--) {
                for (int i=0; i<d.size(); i++) {
                    res.push_back(d[i]);
                }
            }
            solve(c);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;
    while (t--) {
        res.clear();
        unsigned n, k;
        cin >> n;
        vector<int> v(n);
        for (unsigned i=0; i<n; i++) {
            cin >> v[i];
        }
        if (solve(v) == 0) {
            cout << -1 << endl;
        } else {
            for (unsigned i=0; i<res.size(); i++) {
                cout << res[i] << " ";
                if (((i+1) % 3) == 0) {
                    cout << endl;
                }
            }
        }
    }
    
    return 0;
}