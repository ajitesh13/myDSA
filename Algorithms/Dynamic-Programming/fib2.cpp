// build of a table in buttom up fashion and returns the last entry from
// table for the same number we calculate fib(0),fib(1),fib(2) and then fib(3)
// all entries in the table in flled

#include <iostream>
using namespace std;

int fib(int n){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}