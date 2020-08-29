// given n and k find the kth root of n

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << pow(k, (float)(1.0/k)*(log10(n)/log10(k))) << '\n'; // why 1 is not working only 1.0 is working ? 
    return 0;
}