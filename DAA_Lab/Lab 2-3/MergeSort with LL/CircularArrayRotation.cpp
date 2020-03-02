// rotate the array d times 

#include <iostream>
using namespace std;

void rotate(int ar[], int n){
    int p = ar[0];
    for(int i=0; i<n; i++){
        ar[i] = ar[i+1];
    }
    ar[n-1] = p;
}

void makerotation(int ar[], int d, int n){
    while(d--){
        rotate(ar, n);
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