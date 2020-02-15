#include <bits/stdc++.h>
using namespace std;

int Partition(int ar[], int p, int r){
    int pivot = ar[r];
    int i = p-1; // not -1
    int j = p;
    for(j=p; j<=(r-1); j++){
        if(ar[j] < pivot){
            i++;
            swap(ar[j], ar[i]);
        }
    }
    swap(ar[i+1], ar[r]); // why not swap(ar[i+1], pivot);
    return(i+1);
}

void QuickSort(int ar[], int p, int r){
    if(p < r){
        int q = Partition(ar, p, r);
        QuickSort(ar, p, q-1);
        QuickSort(ar, q+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    QuickSort(ar, 0, n-1);
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}