#include <iostream>
#include <cmath>
using namespace std;
class Triangle{
    protected:
        int x;
        int y;
        int z;
    public:
        Triangle(int a, int b, int c){
            x=a;
            y=b;
            z=c;
        }
        void check_and_display();
        void area(int bs, int ht);
        void area(int s1, int s2, int s3);
};
void Triangle::check_and_display(){
    if(z*z == x*x + y*y){
        area(x, y);
    }
    else if(y*y == z*z + x*x){
        area(z, x);
    }
    else if(x*x == y*y + z*z){
        area(y, z);
    }
    else{
        area(x, y, z);
    }
}
void Triangle::area(int bs, int ht){
    cout<<"Area of the Right-Angled-Triangle is: "<<(0.5*bs*ht)<<endl;
}
void Triangle::area(int s1, int s2, int s3){
    double s;
    s = (s1+s2+s3)/2;
    double ar = sqrt( s*(s-s1)*(s-s2)*(s-s3) );
    cout<<"Area of the triangle is: "<<ar<<endl;
}

int main(){
    Triangle t1(3, 4, 5);
    t1.check_and_display();
    Triangle t2(2, 2, 2);
    t2.check_and_display();
    return 0;
}
