// Given two integers N and K, the task is to find the power of K greater than equal to and less than equal to N.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    float b = (float)log10(n)/log10(k);
    cout << pow(k, floor(b)) << " " << pow(k, ceil(b));

    return 0;
}