#include <bits/stdc++.h>
using namespace std;
int res = 0;

void len(string str, int n) {
    if (str[n] == '\0') {
        cout << res << endl;
        return;
    } else {
        res++;
    }
    len(str, n+1);
}

int main() {
    string str;
    cin >> str;
    len(str, 0);
}