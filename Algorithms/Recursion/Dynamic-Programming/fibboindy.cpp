//fibbonacci in dynamic programming using memoization
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define NIL -1

int ar[MAX];

void _init(){
    for (int i = 0; i < MAX; i++){
        ar[i] = -1;
    }
}

int fibbdy(int n){
    if(ar[n] != NIL){
        if(n <= 1){
            ar[n] = n;
        }else{
            ar[n] = fibbdy(n-1) + fibbdy(n-2);
        }
    }
    return ar[n];
}

int main(){
    int n;
    cin >> n;
    cout << fibbdy(n) << endl;
    return 0;
}