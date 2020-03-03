// kth largest element in an array: implimented using modified head sort algorithms
#include <bits/stdc++.h>
using namespace std;

void Heapify(int ar[], int n, int i){ // O(log n)
    int largest = i;
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if(ar[left_child] > ar[largest] && left_child < n){
        largest = left_child;
    }
    if(ar[right_child] > ar[largest] && right_child < n){
        largest = right_child;
    }
    if(largest != i){
        swap(ar[i], ar[largest]);
        Heapify(ar, n, largest);
    }
}

void BuildMaxHeap(int ar[], int n){ // O(n)
    for(int i=(n/2)-1; i>=0; i--){
        Heapify(ar, n, i);
    }
}

int findk(int ar[], int n, int k){
    BuildMaxHeap(ar, n);
    for(int i=n-1; i>=(n-k); i--){
        swap(ar[0], ar[i]);
        Heapify(ar, i, 0);
    }
    return ar[n-k];
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    int k;
    cin >> k;
    cout << findk(ar, n, k) << endl;
    return 0;
}