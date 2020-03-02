#include <iostream>
using namespace std;

int power(int x, int n){
    if(n == 1){
        return x;
    }else{
        int res = x * power(x, n-1);
        return res;
    }
}

int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    cout << power(x,n) << endl;
    return 0;
}