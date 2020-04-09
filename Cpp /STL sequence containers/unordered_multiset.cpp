#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_multiset<int> ums1;
    unordered_multiset<int> ums2({1,3,1,7,2,3,4,1,6});
    ums1 = {2,7,2,5,0,3,7,5};
    if (ums1.empty()) {
        cout << "ums1 is empty";
    } else {
        cout << "ums1 is not empty";
    }
    cout << "\nSize of ums2: " << ums2.size() << '\n';
    int val = 3;
    if (ums1.find(val) != ums1.end()) {
        cout << "ums1 contains " << val << endl;
    } else {
        cout << "ums1 doesn't contains " << val << endl;
    }
    val = 5;
    int count = ums1.count(val);
    cout << val << " appears " << count << " times\n";
    val = 9;
    if (ums1.count(val)) {
        cout << "ums1 contains " << val << endl;
    } else {
        cout << "ums1 doesn't conatins " << val << endl;
    }
    val = 1;
    pair<unordered_multiset<int>::iterator,unordered_multiset<int>::iterator> p = ums2.equal_range(val);
    if (p.first != p.second) {
        cout << val << "appears at least once" << endl;
    }
    unordered_multiset<int>::iterator it3;
    for (it3 = ums2.begin(); it3 != ums2.end(); it3++) {
        cout << (*it3) << " ";
    }
    cout << endl;
    ums1.clear();
    ums2.clear();

    if(ums1.empty()) {
        cout << "ums1 is empty " << endl;
    } else {
        cout << "ums1 is not empty" << endl;
    }
    return 0;
}
