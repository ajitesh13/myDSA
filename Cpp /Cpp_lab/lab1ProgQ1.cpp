#include <iostream>
#include <string>
using namespace std;

class Employee{
	private:
		string emp_id;
		double emp_salary;
	public:
		void in_details();
		void out_details();
};

void Employee::in_details(){
	cout<<"Enter the Employee id:";
	cin>>emp_id;
	cout<<"Enter the Employee Salary:";
	cin>>emp_salary;
}

void Employee::out_details(){
	cout<<"Employee id : "<<emp_id<<'\n';
	cout<<"Emplpoyee Salary : "<<emp_salary<<'\n';
}

int main(){
	Employee ep1;
	ep1.in_details();
	ep1.out_details();
	return 0;
}


