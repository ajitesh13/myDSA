#include <iostream>
using namespace std;

void f(int arr[][2], int n){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << arr[i][j] << endl;
        }
    }
}

int main(){
    int arr1[2][2]={{1, 2},{3, 5}};
    f(arr1, 4);
    return 0;
}

