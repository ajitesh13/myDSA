// A -> 1, 2, 3
// B -> 1, 4
// C -> 5

// 1 -> A, B
// 2 -> A
// 3 -> A
// 4 -> B
// 5 -> C 

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    unordered_map<char, vector<int>> ump;
    ump.insert(make_pair('A', {1, 2, 3}));
    ump.insert(make_pair('B', {1, 4}));
    ump.insert(make_pair('C', {5}));

    unordered_map<int, vector<char>> res;
    for (auto it = ump.begin(); it != ump.end(); it++) {
        cout << *it << ": ";
        for (int i=0; i<it->second.size(); i++) {
            cout << it[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}