#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int,int> um;
    vector<int> v({1,2,2,3,4,4,4,5});
    for (int i=0; i<v.size(); i++) {
        um[v[i]]++;
    }
    for (int i=0; i<v.size(); i++) {
        cout << um[i] << "\n";
    }
    for (auto i: um) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
