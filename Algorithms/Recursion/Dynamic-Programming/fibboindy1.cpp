// fibbo in dynamic porgramming using tabulation

#include <bits/stdc++.h>
using namespace std;

int fibbdy(int n){
    int ar[n+1];
    int i;
    ar[0] = 0;
    ar[1] = 1;
    for(int i=0; i<n; i++){
        ar[i] = ar[i-1] + ar[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin >> n;
    cout << fibbdy(n);
    return 0;
}