#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
	protected:
		double side1;
		double side2;
		double side3;
	public:
		void get_input();
		double show_area();
};

void Triangle::get_input(){
	cout<<"Enter the value of Side 1 of your Triangle: ";
	cin>>side1;
	cout<<"Enter the value of Side 2 of your Triangle: ";
	cin>>side2;
	cout<<"Enter the value of Side 3 of your Triangle: ";
	cin>>side3;
}

double Triangle::show_area(){
	double s;
	double a=side1;
	double b=side2;
	double c=side3;
	s=(a+b+c)/2;
	double area = sqrt(s*(s-a)*(s-b)*(s-c)) ;
	return(area);
}

int main(){
	Triangle t1, t2, t3;
	cout<<"Give Input for the first Triangle:"<<'\n';
	t1.get_input();
	cout<<"Give Input for the Second Triangle:"<<'\n';
	t2.get_input();
	cout<<"Area of the Triagle is: "<<t1.show_area()<<'\n';
	cout<<"Area of the Triangle is: "<<t2.show_area()<<'\n';
	return(0);
}