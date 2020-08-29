// for checking if a number is a power of 2 or not

#include <bits/stdc++.h>
using namespace std;

bool gen(int n) {
    return (ceil(log2(n)) == floor(log2(n)));
}

int main() {
    int n;
    cin >> n;
    if (gen(n)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}