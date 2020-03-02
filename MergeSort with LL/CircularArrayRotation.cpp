#include <iostream>
using namespace std;

void rotate(int ar[], int d, int n){
    int temp = ar[0];
    int new_ar[n];
    for(int i=0; i<n; i++){
        new_ar[i] = ar[i+1];
    }
    new_ar[n-1] = temp;
}

void makerotation(int ar[], int d, int n){
    for(int i=d; d>=1; d--){
        rotate(ar, 1, n);
    }
}

int main(){
    int n;
    cin >> n;
    int d;
    cin >> d;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    makerotation(ar, d, n);
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}