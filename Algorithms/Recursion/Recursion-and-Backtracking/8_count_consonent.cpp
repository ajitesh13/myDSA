#include <bits/stdc++.h>
using namespace std;
int res = 0;

void cntcon(string& str, int n) {
    if (n == str.size()) {
        cout << res << endl;
        return;
    } else {
        if (str[n] != 'a' && str[n] != 'e' && str[n] != 'i' && str[n] != 'o' &&str[n] != 'u' &&
            str[n] != 'A' && str[n] != 'E' && str[n] != 'I' && str[n] != 'O' &&str[n] != 'U' &&
            str[n] != ' '
        ) {
            res++;
        } 
        cntcon(str, n + 1);
    }
}

int main() {
    string str;
    // cin >> str;
    getline(cin, str, '\n');
    cntcon(str, 0);
    return 0;
}