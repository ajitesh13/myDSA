#include <iostream>
using namespace std;

int main(){
    int p = 10;
    int *ptr = &p;
    int **qtr = &ptr;
    cout << ptr << " " << *ptr << " " << &p << endl;
    cout << qtr << " " << *qtr << " " << **qtr << endl;
    return 0;
}