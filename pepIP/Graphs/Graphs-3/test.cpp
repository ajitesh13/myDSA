#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_set<string> s = {"hit", "hoz"};
    string a = "hot";
    string a1 = a;
    string z = "hot";
    int cnt = 0;
    for (int i=0; i<a.size(); i++) {
        for (int j=97; j<=122; j++) {
            a[i] = (char)j;
            if (s.find(a) != s.end()) {
                cnt++;
                cout << a << '\n';
            }
        }
        a = a1;
    }
    return 0;
}
