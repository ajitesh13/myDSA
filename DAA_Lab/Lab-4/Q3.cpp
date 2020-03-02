// Find the maximum element in an array which is first increasing and then decreasing

// compute the sieve of erostein uptill 1000
// find all the palondromic date in a given century

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // vector<int> v;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int flag;
    for(int i=0; i<n-1; i++){
        if(v[i] > v[i+1]){
            flag = i;
            break;
        }
    }
    cout << v[flag] << endl;
    return 0;
}