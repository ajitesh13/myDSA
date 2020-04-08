#include <bits/stdc++.h>
using namespace std;

void printDuplicates(int ar[], int n) {
    unordered_set<int> is;
    unordered_set<int> dup;
    for (int i=0; i<n; i++) {
        if (is.find(ar[i]) == is.end()) {
            is.insert(ar[i]);
        } else {
            dup.insert(ar[i]);
        }
    }
    cout << "Dup items are: ";
    unordered_set<int>::iterator it;
    for (it = dup.begin(); it != dup.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string> s;
    s.insert("code");
    s.insert("in");
    s.insert("cpp");
    s.insert("is");
    s.insert("fast");

    string key = "slow";
    if (s.find(key) == s.end()) {
        cout << "Not Found!" << endl;
    } else {
        cout << "Found " << key << endl;
    }
    key = "cpp";
    if (s.find(key) == s.end()) {
        cout << key << "not found" << endl;
    } else {
        cout << "found " << key << endl;
    }
    unordered_set<string>::iterator is;
    for (is=s.begin(); is != s.end(); is++) {
        cout << (*is) << " ";
    }

    unordered_set<int> s1;
    unordered_set<int>::iterator it;
    s1.insert(1);
    s1.insert(5);
    s1.insert(2);
    s1.insert(4);
    s1.insert(3);
    s1.insert(6);
    for (it = s1.begin(); it != s1.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;

    // Q. Given a set of integers, find all the duplicates among them
    // INPUT:- ar = {1,5,2,1,4,3,1,7,2,8,9,5}
    // OUTPUT:- 5, 2, 1
    int ar[] = {1,5,2,1,4,3,1,7,2,8,9, 5};
    int n = sizeof(ar) / sizeof(ar[0]);
    printDuplicates(ar, n);
    return 0;
}