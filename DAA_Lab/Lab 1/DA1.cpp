#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int x,root,i=1,sqr;
	cout<<"Enter a number :"<<endl;
	cin>>x;
	sqr = i*i;
	while(sqr<=x){
		i++;
		sqr = i*i;
	}
	if(sqr>x){
		i=i-1;
	}
	cout<<i<<endl;
}