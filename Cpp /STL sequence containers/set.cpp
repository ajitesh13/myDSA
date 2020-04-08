#include <bits/stdc++.h>
using namespace std;

int main() {
    // set<int> s; // sort elements in ascending order
    set<int, greater<int>> s; // sort element in decending order
    s.insert(40);
    s.insert(30);
    s.insert(60);
    s.insert(20);
    s.insert(40);
    s.insert(50);
    s.insert(10);

    set<int, greater<int>>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    set<int, greater<int>> s1(s.begin(), s.end()); // writing the element from s to s1
    s1.erase(s1.begin(), s1.find(30)); // erase elements greater than 30
        for (it = s1.begin(); it != s1.end(); it++) {
        cout << *it << ' ';
    }

    int n = s1.erase(50); // n holds the number of occurance of the erased element (in set the value can be zero or one but in multiset it can be more)
    cout << n <<'\n';


    return 0;
}