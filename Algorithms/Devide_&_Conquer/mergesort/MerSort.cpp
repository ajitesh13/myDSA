#include <bits/stdc++.h>
using namespace std;

void Merge(int ar[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int Temp1[n1]={0};
    int Temp2[n2]={0};
    for(int i=0; i<n1; i++){
        Temp1[i] = ar[p+i];
    }
    for(int j=0; j<n2; j++){
        Temp2[j] = ar[q+1+j];
    }
    int i = 0;
    int j = 0;
    int k = p;

    while(i<n1 && j<n2){
        if(Temp1[i] <= Temp2[j]){
            ar[k] = Temp1[i];
            i++;
        }else{
            ar[k] = Temp2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        ar[k] = Temp1[i];
        i++;
        k++;
    }
    while(j < n2){
        ar[k] = Temp2[j];
        j++;
        k++;
    }
}

void MergeSort(int ar[], int p, int r){
    if(p < r){
        int q = p + (r-p)/2; // better than (p+r)/2
        MergeSort(ar,p,q);
        MergeSort(ar,q+1,r);
        Merge(ar,p,q,r);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    MergeSort(ar, 0, n-1);
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}