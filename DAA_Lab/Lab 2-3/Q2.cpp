//     Search in nearly sorted array in minimum time
//     a. Given a nearly sorted array (degree of misplaced element is no more than one position from correct place), efficiently search an element in it.
//     b. Input – [2, 1, 3, 4, 5, 6, 7, 8, 9]; 5
//     c. Output – Position of 5 = 4th (or index = 4)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int>::iterator iter;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << endl;
    for(int i=0; i<(n-1); i++){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
            break;
        }
    }
    cout << endl;
    int search;
    cin >> search;
    iter = lower_bound(v.begin(), v.end(), search);
    cout << (iter - v.begin());
    return 0;
}