// 1 -> 56

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main() {
    vector<int> v = {1, 7, 8, 3, 12};

    unordered_map<int, unordered_set<int>> ump;

    for (int i=0; i<v.size(); i++) {
        unordered_set<int> us;
        us.insert(56);
        ump.insert(mp(v[i], us));
    }
    
    for (int i=0; i<v.size(); i++) {
        unordered_set<int> us = ump.find(v[i])->second;
        unordered_set<int> us1;
        for (auto it = us.begin(); it!=us.end(); it++) {
            us1.insert(*it);
        }
        us1.insert(67);
        ump.find(v[i])->second = us1;
    }

    for (auto it = ump.begin(); it != ump.end(); it++) {
        cout << it->first << ": ";
        for (auto ait = it->second.begin(); ait!=it->second.end(); ait++) {
            cout << *ait << ' ';
        }
        cout << '\n';
    }

    return 0;
}