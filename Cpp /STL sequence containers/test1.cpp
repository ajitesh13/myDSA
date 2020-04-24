#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<int> s;
    s.insert(11);
    s.insert(9);
    s.insert(11);
    s.insert(9);
    set<int, greater<int>>::iterator sit;
    for (sit = s.begin(); sit != s.end(); sit++) {
        cout << *sit << " ";
    }

    return 0;
}
