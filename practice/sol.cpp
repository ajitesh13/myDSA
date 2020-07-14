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

    string pattern = "abba";
    string str = "dog cat cat dog";
    vector<string> s;
    vector<string> p;
    const char delims = ' ';
    string hs;
    stringstream sss(str);
    for (int i=0; i<pattern.size(); i++) {
        p.push_back(pattern[i]);
    }
    while (getline(sss, hs, delims)) {
        s.push_back(hs);
    }
    int cntr = 0;
    unordered_map<string,string> ums;
    for (int i=0; i<p.size(); i++) {
        if (ums.find(p[i]) == ums.end()) {
            ums.insert(make_pair(p[i], s[i]));
        } else {
            if (ums.at(p[i]) == s[i]) {
                ums.insert(make_pair(p[i], s[i]));
            } else {
                cntr++;
                break;
            }
        }
    }
    if (cntr == 0) {
        return true;
    } else {
        return false;
    }

    return 0;
}
