// finding ugly numbers by iteration
#include <bits/stdc++.h>
using namespace std;

int maxdevide(int num, int d) {
    while(num % d == 0) {
        num = num / d;
    }
    return num;
}

int checkugly(int i) {
    i = maxdevide(i, 2);
    i = maxdevide(i, 3);
    i = maxdevide(i, 5);
    if(i == 1){
        return 1;
    }else{
        return 0;
    }
}

int ugly(int n) {
    int i=1;
    int count = 1;
    while(count < n) {
        i++;
        if(checkugly(i)) {
            count++;
        }
    }
    return i;
}

int main(){
    int n;
    cin >> n;
    cout << ugly(n) << endl;
    return 0;
}