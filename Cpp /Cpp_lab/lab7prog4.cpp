// 4. Write a program where an exception of type float can be rethrown.

#include <iostream> 
using namespace std; 

void f() {
    try{
        cout << "In try function" << endl;
        throw 4.4f;
    }
    catch(float e){
        cout << "Caught Exception" << e << endl;
        throw;
    }


    
} 


int main() 
{ 
    try{
        cout << "In try of main()" << endl;
        func(); 
    }
    catch(float be){
        cout << "caught rethrown exception" << be << endl;
    }
    return 0; 
}