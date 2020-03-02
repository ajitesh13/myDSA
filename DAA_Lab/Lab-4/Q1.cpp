/* Inversion Count of an Array :-
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3). */

// 1. brute force

#include <bits/stdc++.h>
using namespace std;

int count_inversion(int v[], int n){
    int count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(v[i] > v[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << count_inversion(v, n) << endl;
    return 0;
}

// 2. using enhance merge sort
// 3. using self balancing Binary search tree 
// 4. using set
// 5. using binary indexed tree
