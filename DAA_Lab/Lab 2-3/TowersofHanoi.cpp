#include <iostream>
using namespace std;

void TOH(int n, char l, char m, char r){
    if(n == 1){
        cout << "Move " << l << " to " << r << endl;
        return;
    }else{
        TOH(n-1, l, r, m);
        TOH(1, l, m, r);
        TOH(n-1, m, l, r);
    }
}

int main(){
    int n;
    cin >> n;
    char l = 'L', r = 'R', m = 'M';
    TOH(n, l, m, r);
    return 0;
}