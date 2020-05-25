#include <iostream>
using namespace std;
class Shape{
    private:
        double x;
        double y;
    public:
        void area(double a);
        void area(double c, double d);
}; 
void Shape::area(double a){
    cout<<"Area of the Square is: "<<a*a<<endl; 
}
void Shape::area(double c, double d){
    cout<<"Area of the Rectangle is: "<<c*d<<endl;
}

int main(){
    Shape sq, rec;
    sq.area(5.0);
    rec.area(2.0, 3.0);
    return 0;
}