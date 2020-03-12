// fibbonacci program using dynamic prgogramming
// method - 1: memoization(top-down):- declaring a nil table and then search for the required value in the table, if found use it
// if not, compute and store it
// all entries in the table are not necesarrily be filled

#include <iostream>
using namespace std;
#define MAX 100
#define NIL -1

int lookup[MAX];

void _initialize()
{  
    int i;  
    for (i = 0; i < MAX; i++)  
        lookup[i] = NIL;
}

// function for nth fibbonacci
int fib(int n){
    if(lookup[n] == NIL){
        if(n <= 1){
            lookup[n] = n;
        }else{
            lookup[n] = fib(n-1) + fib(n-2);
        }
    }
    return lookup[n];
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}