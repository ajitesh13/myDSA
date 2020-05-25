#include <iostream>
using namespace std;

inline int cube(int i){
    return(i*i*i);
}

int main(){
    int a;
    cin>>a;
    cout<<cube(a)<<endl;
    return 0;
}