// 2. Write a program where a user defined function is capable 
//    of throwing exceptions of type double only.




#include <iostream> 
using namespace std; 

void f(int k) throw(double){
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