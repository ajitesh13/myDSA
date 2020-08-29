// count number of digits 

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    cout << floor(log10(n)) + 1 << '\n';
    return 0;
}