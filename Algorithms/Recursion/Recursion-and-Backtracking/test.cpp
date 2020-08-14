#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> res;
    res.push_back(1);
    res.push_back(0);
    res.push_back(1);
    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++) {
        cout << res[i];
    }
    res.clear();
    cout << '\n' << res.size() << endl; 
    return 0;
}