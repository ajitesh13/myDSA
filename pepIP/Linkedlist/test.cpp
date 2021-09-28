#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    long long int k,c=0;
	    cin>>k;
	    vector<long long int>v;
	    stack<long long int>s1;
	    for(int i=0;i<s.length();i++)
	    {
	        long long int y=s[i]-'0';
	        if(y==k)
	        {
	            c++;
	        }
	        else if(!s1.empty() && (y+s1.top())==k)
	        {
	              c++;s1.pop();
	        }
	        else 
	        {
	            s1.push(y);
	        }
	    }
	    if((c%2)==0)
	    cout<<"B"<<endl;
	    else
	    cout<<"A"<<endl;
	
	}
	return 0;
}