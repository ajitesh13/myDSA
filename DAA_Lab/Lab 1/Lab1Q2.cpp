#include <iostream>
using namespace std;

int find_the_missing_AP_element(int a[],int n){
	int d1 = a[1] - a[0];
	int d2 = a[2] - a[1];
	int d = (d1 < d2) ? d1 : d2;
	for(int i=0; i<n; i++){
		if(a[i+1]-a[i] != d){
			return (a[i] + d);
		}
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	cout << find_the_missing_AP_element(a,n) << endl;
	return 0;
}