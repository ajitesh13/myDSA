#include <iostream>
#include <string>
using namespace std;

class Customers{
	private:
		unsigned long long int account_number;
		double balance_amount;
		string PAN_number;
	public:
		void get_info();
		void show_info();
		int acc_no[200];
		double bal_am[200];
		string pan[200]; 
		int n;
};

void Customers::get_info(){
	cout<<"Enter the numbers of customers: ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<"Enter Account Number of Customer "<<(i+1)<<": ";
		cin>>acc_no[i];
		cout<<"Enter the Balance Amount of Customer"<<(i+1)<<": ";
		cin>>bal_am[i];
		cout<<"Enter the PAN Number of Customer"<<(i+1)<<": ";
		cin>>pan[i];
	}
}

void Customers::show_info(){
	for(int i=0; i<n; i++){
		cout<<"Account Number of Customer "<<(i+1)<<": ";
		cout<<acc_no[i]<<'\n';
		cout<<"Balance Amount of Customer "<<(i+1)<<": ";
		cout<<bal_am[i]<<'\n';
		cout<<"PAN Number of Customer "<<(i+1)<<": ";
		cout<<pan[i]<<'\n';
	}
}

int main(){
	Customers c1;
	c1.get_info();
	c1.show_info();
	return 0;
}