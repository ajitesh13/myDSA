#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int n,dif=0,num;
	cout<<"Enter the size of array : "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the AP series : "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];}
	for(int i=0;i<n-1;i++){
		if(dif>arr[i+1]-arr[i] && dif!=0){
			num = (arr[i-1]+arr[i])/2;
			i=n;
		}
		else if(dif<arr[i+1]-arr[i] && dif!=0){
			num = (arr[i+1]+arr[i])/2;
			i=n;
		}
		dif = arr[i+1]-arr[i];
	}
	cout<<"Missing Term is "<<num<<endl;
}