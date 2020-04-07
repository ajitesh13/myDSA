// sorting in perticular order: https://www.geeksforgeeks.org/sort-c-stl/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {5,7,3,2,8,7,9};
    sort(v.begin(), v.end()); // sort in ascending order
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
    sort(v.begin(), v.end(), greater<int>()); // sort in decending order
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
