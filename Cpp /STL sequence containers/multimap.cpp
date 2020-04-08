// similar to map plus some other benefits
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int,int> mm;
    mm.insert(pair<int,int>(1,40));
    mm.insert(pair<int,int>(2,30));
    mm.insert(pair<int,int>(3,60));
    mm.insert(pair<int,int>(4,20));
    mm.insert(pair<int,int>(5,50));
    mm.insert(pair<int,int>(6,50));
    mm.insert(pair<int,int>(6,50));
    mm.insert(pair<int,int>(6,10));
    multimap<int,int>::iterator imm;
    for (imm = mm.begin(); imm != mm.end(); imm++) {
        cout << imm->first << " " << imm->second << endl;
    }

    return 0;
}