// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int n, q;
//     cin >> n >> q;
//     while(n--){
//         int size;
//         cin >> size;
//         int a[n][size];
//         for (int j = 0; j < size;j++){
//             cin >> a[0][j];
//         }
//         int x, y;
//         for(int i=0; i<q; i++){
//             cin >> x >> y;
//         }
//         cout << a[x][y];
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main(){
        int n, q;
    cin >> n >> q;

    int **arr = new int*[n];
    for ( int i = 0, k ; i < n ; ++ i )
    {
        cin >> k;
        
        arr[i] = new int[k];
        
        for ( int j = 0 ; j < k ; ++ j )
        {
            cin >> arr[i][j];
        }
    }
    
    for ( int i = 0, a, b ; i < q ; ++ i )
    {
        cin >> a >> b;
        
        cout << arr[a][b] << endl;
    }
    
	return 0;
}