/*
#include <iostream>
using namespace std;

void f(double d);
void f(float f);

int main(){
    f(10);
    f(20.5);
    return 0;
}

void f(double d){
    cout<<"d = "<<d<<endl;
}

void f(float f){
    cout<<"f = "<<f<<endl;
}

*/

#include <iostream>
using namespace std;
int f(int a, int b){
    return a+b;
}
void f(int a, int b){
    cout<<(a+b)<<endl;
}
int main(){
    cout<<f(100, 200)<<endl;
    return 0;
}   