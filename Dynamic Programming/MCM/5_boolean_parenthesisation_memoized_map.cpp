#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> ump;
int solve(string s, int i, int j, bool isTrue) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue == true) {
            return s[i] == 'T';
        } else {
            return s[i] == 'F';
        }
    }
    string key = to_string(i);
    key.push_back(' ');
    key.append(to_string(j));
    key.push_back(' ');
    key.append(to_string(isTrue));
    if (ump.find(key) != ump.end()) {
        return ump[key];
    } else {
        int ans = 0;
        for (int k=i+1; k<=j-1; k++) {
            if (s[k] != 'T' and s[k] != 'F') {
                int lt = solve(s, i, k-1, true);
                int lf = solve(s, i, k-1, false);
                int rt = solve(s, k+1, j, true);
                int rf = solve(s, k+1, j, false);
                if (s[k] == '&') {
                    if (isTrue == true) {
                        ans += lt*rt;
                    } else {
                        ans += lt*rf + lf*rt + lf*rf;
                    }
                } else if (s[k] == '|') {
                    if (isTrue == true) {
                        ans += lt*rt + lt*rf + lf*rt;
                    } else {
                        ans += lf*rf;
                    }
                } else if (s[k] == '^') {
                    if (isTrue == true) {
                        ans += lt*rf + lf*rt;
                    } else {
                        ans += lt*rt + lf*rf;
                    }
                }
            }
        }
        return ump[key] = ans;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "T|T&F^T"; // 4
    // string s = "T^F|F"; // 2
    // string s = "T^F&T"; // 2
    cout << solve(s, 0, s.length()-1, true) << "\n";
    
    return 0;
}
