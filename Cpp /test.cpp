#include <iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    int **outer = new int*[n];
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        outer[i] = new int[k]; // create a array of length 'k' at index 'i'

        //fill each cell in 'inner' variable length array
        for(int j=0; j<k; j++){
            cin >> outer[i][j];
        }
    }
    while(q-- > 0){
        int outer_index;
        int inner_index;
        cin >> outer_index >> inner_index;
        cout << outer[outer_index][inner_index];
    }
    return 0;
}