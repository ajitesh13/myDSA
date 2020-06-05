#include <iostream>
using namespace std;

void TSearch(int ar[], int p, int r, int search){
    if(p <= r){
        int m1 = p + (r-p)/3;
        int m2 = r - (r-p)/3;
        if(search == ar[m1]){
            cout << m1;
        }else if(search == ar[m2]){
            cout << m2;
        }else{
            TSearch(ar, p, m1-1, search);
            TSearch(ar, m1+1, m2-1, search);
            TSearch(ar, m2+1, r, search);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    int search;
    cin >> search;
    TSearch(ar, 0, n-1, search);
    return 0;
}