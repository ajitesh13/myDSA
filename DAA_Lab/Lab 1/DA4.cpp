#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int n;
	string name,prefix="";
	cout<<"Enter the number of Strings : "<<endl;
	cin>>n;
	vector<string> names;
	cout<<"Enter the strings : "<<endl;
	for(int i=0;i<n;i++){
		cin>>name;
		names.push_back(name);
	}
	prefix=names[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<names[i].size();j++){
			if(prefix[j]==names[i][j]){

			}
			else{
				prefix=prefix.substr(0,j);
				j= names[i].size();
			}
		}
	}
	cout<<prefix<<endl;
}