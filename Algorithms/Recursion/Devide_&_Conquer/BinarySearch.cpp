#include <bits/stdc++.h>
using namespace std;

int BSearch(int ar[], int x, int p, int r){
    if(p == r){
        if(x == ar[p]){
            return p;
        }else{
            return -1;
        }
    }else{
        int q = (p+r)/2;
        if(x <= ar[q]){
            BSearch(ar, x, p, q);
        }else{
            BSearch(ar, x, q+1, r);
        }
    }
}

int main(){
    int n = 3;
    // cin >> n;
    int ar[3] = {3, 1, 2};
    // for(int i=0; i<n; i++){
    //     cin >> ar[i];
    // }
    int search;
    cin >> search;
    cout << BSearch(ar, search, 0, n-1) << endl;
    return 0;
}