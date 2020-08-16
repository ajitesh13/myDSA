#include <bits/stdc++.h>
using namespace std;

void firstUP(string str, int n) {
    if (int(str[n]) >= 65 && int(str[n]) <= 90) {
        cout << str[n] << '\n';
        return;
    } else {
        firstUP(str, n+1);
    }
    return;
}

int main() {
    string str;
    cin >> str;
    firstUP(str, 0);
    return 0;
}