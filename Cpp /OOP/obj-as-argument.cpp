#include <iostream>
using namespace std;

class Distance{
    private:
        int feet;
        float inches;
    public:
        Distance(int ft, float in){
            feet = ft;
            inches = in;
        }
        Distance(){} //overloaded contructor
        void getdist();
        void showdist();
        void add_dist(Distance d1, Distance d2);
};

void Distance::getdist(){
    cout<<"Feet: "; cin>>feet;
    cout<<"Inches: "; cin>>inches;
}

void Distance::showdist(){
    cout<<"Feet: "<<feet<<endl;
    cout<<"Inches: "<<inches<<endl;
}

void Distance::add_dist(Distance d1, Distance d2){ //object passed as the argument of the 
    feet = d1.feet + d2.feet;                      // member function and the result is stored  
    inches = d1.inches + d2.inches;                // in the variable of the object, with which 
    cout<<"Sum of feet: "<<feet<<endl;             // it was called with dot operator
    cout<<"Sum of inches: "<<inches<<endl;
}

int main(){
    Distance ob1(2, 5.0);
    cout<<"ob1: ";
    ob1.showdist();
    Distance ob2, ob3;
    ob2.showdist();
    ob2.getdist();
    //ob3.getdist();
    ob3.add_dist(ob1, ob2);
    //ob3.showdist();
    return 0;
}