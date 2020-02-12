#include <iostream>
using namespace std;

int main(){
    int a = 5, b = 9;
    cout << (5<<1) << endl; // before shift: 101, after shift: 1010(=10)
    cout << (9<<1) << endl; // before shift: 1001, after shift: 10010(=19)
    return 0;
}