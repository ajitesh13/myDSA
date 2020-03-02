#include <iostream>
using namespace std;

int TS(int ar[], int p, int r, int search){
    if(p < r){
        int m1 = p + (r-p)/3;
        int m2 = r - (r-p)/3;
        if(p < m1 && r > m2){
            if(ar[m1] == search){
                return m1;
            }else if(ar[m2] == search){
                return m2;
            }else{
                TS(ar, p, m1-1, search);
                TS(ar, m1+1, m2-1, search);
                TS(ar, m2+1, r, search);
            }
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
    cout << TS(ar, 0, n-1, search) << endl;
    return 0;
}