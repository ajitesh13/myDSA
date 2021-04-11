#include <bits/stdc++.h>
using namespace std;

bool ispal(string s, int i, int j) {
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else return false; 
    }
    return true;
}

int palindromepartition(string s, int i, int j) {
    if (i >= j) 
        return 0;
    if (ispal(s, i, j)) 
        return 0;
    int mn = INT32_MAX;
    for (int k=i; k<=j-1; k++) {
        int tempans = palindromepartition(s, i, k) + palindromepartition(s, k+1, j) + 1;
        mn = min(mn, tempans);
    }
    return mn;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "abcde";
    int n = s.size();
    cout << palindromepartition(s, 0, n-1) << "\n";
    
    return 0;
}
