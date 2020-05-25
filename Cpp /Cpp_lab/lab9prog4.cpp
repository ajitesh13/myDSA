// 4. How can you declare and define a const object for a given class with protected attributes of type char and int? 
// Provide appropriate method initialize the attributes and display the result.

#include <iostream>
using namespace std;

class A{
    protected:
        int i;
        char c;
    public:
        A(int a, char h){
            i = a;
            c = h;
        }
        void display() const{
            cout << "i = " << i << endl;
            cout << "c = " << c << endl;
        }
};

int main(){
    A const ob(20, 'A');
    ob.display();
    return 0;
}