// #include <iostream>
// using namespace std;

// void search(int mat[4][4], int fromRow, int toRow, int fromCol, int toCol, int search){
//     int i = fromRow + (toRow - fromRow)/2;
//     int j = fromCol + (toCol - fromCol)/2;
//     if(mat[i][j] == search){
//         cout << "Found at "
//     }
// }

// int main(){
//     int mat[4][4] = {
//         {10,20,30,40},
//         {15,25,35,45},
//         {27,29,37,48},
//         {32,33,39,50}
//     };
//     int search = 50;
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             search(mat, 0, 3, 0, 3, mat[i][j]);
//         }
//     }
//     return 0;
// }