#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int C,l,days = 0,i=0,temp;
	cout<<"Enter the Capacity of tank : "<<endl;
	cin>>C;
	temp = C;
	cout<<"Enter the daily addition quantity : "<<endl;
	cin>>l;
	while(C>0){
		i++;
		days++;
		C=C+l-i;
		if(C>temp){
			C=temp;
		}
	}
	cout<<"Tank will be empty in "<<days-1<<" days."<<endl;
}