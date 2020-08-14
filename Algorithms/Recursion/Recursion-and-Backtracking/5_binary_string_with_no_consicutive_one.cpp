#include <bits/stdc++.h>
using namespace std;

void store(string str, int k) {
    if (str.size() == k) {
        cout << str << endl;
        return;
    }
    auto it = str.end();it--;
    if (*it == '0') {
        str.push_back('0');
        store(str, k);
        str.pop_back();
        str.push_back('1');
        store(str, k);
    }
    if (*it == '1') {
        str.push_back('0');
        store(str, k);
    }
}

void gen(int k) {
    store("0", k);
    store("1", k);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        gen(k);
    }
    return 0;
}