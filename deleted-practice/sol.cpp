// A -> 1, 2, 3
// B -> 2, 4
// C -> 5

// 1 -> A
// 2 -> A, B
// 3 -> A
// 4 -> B
// 5 -> C

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << 'e';
    map<char, vector<int>> mp;
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 4};
    vector<int> c = {5};
    mp.insert(make_pair('A', a));
    mp.insert(make_pair('B', b));
    mp.insert(make_pair('C', c));
    set<int> s;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i=0; i<it->second.size(); i++) {
            s.insert(it->second[i]);
        }
    }

    for 
    vector<char> nullvec;
    map<int, vector<char>> res;

    cout << 1;

    for (auto it=s.begin(); it!=s.end(); it++) {
        res.insert(make_pair(*it, nullvec));
    }

    cout << 2;

    for (auto it=mp.begin(); it!=mp.end(); it++) {
        int value = it->first;
        for (int i=0; i<it->second.size(); it++) {
            res[it->second[i]].push_back(value);
        }
    }

    cout << 3;
    
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << it->first << " ";
        cout << 'j';
        for (int i = 0; i<it->second.size(); it++) {
            cout << it->second[i] << ' ';
        }
        cout<< '\n';
    }

    cout << 4;



    return 0;
}