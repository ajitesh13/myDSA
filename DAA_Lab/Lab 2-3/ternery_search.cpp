1,2,3,4,5,6
#include <iostream>
using namespace std;

void TernerySearch(int ar[], int p, int r, int search){
    if(p == r){
        if(ar[p] == search){
            return p;
        }else{
            return -1;
        }
    }else if(p < r){
        int q1 = (r-p)/3;
        int q2 = (r-)
    }
}

int main(){
    int ar = {1,2,3,4,5};
    int n;
    cin >> n;
    int search;
    cin >> search;
    cout << TernerySearch(ar, 0, n-1, search) << endl;
    return 0;
}