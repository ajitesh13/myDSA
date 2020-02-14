#include <bits/stdc++.h>
using namespace std;

int partition(int ar[], int p, int r){
    int x = ar[r];
    int i = p - 1;

    for(int j=p; j<(r-1); j++){
        if(ar[j] <= x){
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i+1], ar[r]);
    return(i+1);
}

void QSort(int ar[], int p, int r){
    if(p < r){
        int q = partition(ar, p, r);
        QSort(ar, p, q-1);
        QSort(ar, q+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    QSort(ar, 0, n-1);
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    return 0;
}