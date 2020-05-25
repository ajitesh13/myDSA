#include <iostream>
using namespace std;
class Area{
    private:
        int a, b;
    public:
        int area1(int a){
            return a*a;
        }
        int area2(int a, int b=10){
            return a*b;
        }
};
int main(){
    int s, t;
    Area obj;
    cout<<"Enter values of x, y"<<endl;
    cin>>s>>t;
    obj.area(s, t); //No Ambiguity 
    obj.area(s); //Ambiguity arises
    // The ambiguity arises because the compiler will not understand 
    // which meber function to call as only one argument is passed
    return 0;

}