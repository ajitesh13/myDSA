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

    vector<char> p;
    for (int i=0; i<pattern.size(); i++) {
        p.push_back(pattern[i]);
    }
    vector<string> s;
    stringstream ss(str);
    string hs;
    const char delim = ' ';
    while (getline(ss, hs, delim)) {
        s.push_back(hs);
    }
    unordered_map<char,string> um;
    unordered_set<string> us;
    if (s.size() == p.size()) {
        for (int i=0; i<p.size(); i++) {
            if (um.find(p[i]) == um.end()) {
                um.insert(make_pair(p[i], s[i]));
                if (us.find(s[i]) == us.end()) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (um.at(p[i]) != s[i]) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
    
    return 0;
}
