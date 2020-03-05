#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    }else{
        gcd(b%a, a);
    }
}

int main(){
    cout << gcd(15, 10);
    return 0;
    return 0;
}