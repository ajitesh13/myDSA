#include <bits/stdc++.h>
using namespace std;

int expo(int a, int b){
    if(b == 1){
        return a;
    }else{
        a = a*b;
        expo(a, b--);
    }

}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << (expo(a, b) % c) << endl;
    return 0;
}