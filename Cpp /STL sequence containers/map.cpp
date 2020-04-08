#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> m;
    m.insert(pair<int,int>(1,40));
    m.insert(pair<int,int>(7,10));
    m.insert(pair<int,int>(3,60));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(5,70)); // doesn't allow duplicate keys
    m.insert(pair<int,int>(2,30));
    m.insert(pair<int,int>(4,20));
    m.insert(pair<int,int>(6,50));


    map<int,int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    map<int,int> m1(m.begin(), m.end());
    for (it = m1.begin(); it != m1.end(); it++) {
        cout << it->first << " " << it->second << endl ;
    }

    return 0;
}