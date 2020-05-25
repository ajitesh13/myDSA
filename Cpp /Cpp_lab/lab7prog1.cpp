// 1. Write a program where a single catch block is capable of handling any type of exception.





#include <iostream> 
using namespace std; 

void f(int k){
    cout << "Thrrow exception" << endl;
    if(k==0)
        throw 404;
    else if(k==1)
        throw 79.2;
    else if(k==2)
        throw 'Z';
    else 
        throw "wow";
}  

int main() 
{ 
    cout << "Enter an integer" << endl;
    int i;
    cin >> i;
    try  { 
       f(i); 
    } 
    catch (...)  { 
        cout << "Caught Exception\n"; 
    } 
    return 0; 
}