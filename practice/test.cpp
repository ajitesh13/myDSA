#include <iostream>
using namespace std;

// int sum(int n){
//     if(n < 0){
//         return 0;
//     }
//     return n + sum(n-1);
// } /* The Function takes O(n) time and space complexity */

int pairSum(int a,int b);
int pairSumSequence(int n);


int main(){
    cout << pairSumSequence(4) << endl;
    return 0;
}

int pairSumSequence(int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += pairSum(i,i+1);
    }
    return sum;
}
int pairSum(int a, int b){
    return a+b;
}