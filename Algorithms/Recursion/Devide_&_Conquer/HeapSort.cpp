#include <bits/stdc++.h>
using namespace std;

void Heapify(int ar[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(ar[l] > ar[largest] && l < n){
        largest = l;
    }
    if(ar[r] > ar[largest] && r < n){
        largest = r;
    }
    if(i != largest){
        swap(ar[i], ar[largest]);
        Heapify(ar, n, largest);
    }
}

void BuildHeap(int ar[], int n){
    for(int i= n/2 - 1; i >= 0; i--){
        Heapify(ar, n, i);
    }
}

void HeapSort(int ar[], int n){
    BuildHeap(ar, n);
    for(int i=n-1; i>=1; i--){
        swap(ar[0], ar[i]);
        Heapify(ar, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    HeapSort(ar, n);
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}