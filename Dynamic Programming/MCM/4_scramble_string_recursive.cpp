#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b) {
    if (a.length() != b.length()) return false;
    if (a.empty() and b.empty()) return true;
    if (a == b) return true;
    if (a.length() <= 1) return false;

    int n = a.length();
    bool flag = false;
    for (int i=1; i<=n-1; i++) {
        bool subcond1 = solve(a.substr(0, i), b.substr(n-i, i));
        bool subcond2 = solve(a.substr(i, n-i), b.substr(0, n-i));
        bool cond1 = subcond1 and subcond2;
        bool subcond3 = solve(a.substr(0, i), b.substr(0, i));
        bool subcond4 = solve(a.substr(i, n-i), b.substr(i, n-i));
        bool cond2 = subcond3 and subcond4;

        if (cond1 or cond2) {
            flag = true;
            break;
        } 
    }
    return flag;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "coder";
    string b = "ocder"; // 1

    // string a = "abcde";
    // string b = "caebd"; // 0

    cout << solve(a, b) << "\n";
    
    return 0;
}
