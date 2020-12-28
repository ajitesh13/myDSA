#include <bits/stdc++.h>
using namespace std;

char reval(int num) {
    if (num >= 0 && num <= 9) return (char)(num + '0');
    else return (char)(num-10 + 'A');
}

string fromDeci(int n, int base) {
    string res = "";
    while (n > 0) {
        res.push_back(reval(n%base));
        n = n/base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 2;
    int base = 3;

    cout << fromDeci(n, base) << '\n';
    
    return 0;
}
