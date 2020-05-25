#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

int main() {
	// your code goes here
	int t ;
	cin>>t ;
	while(t--)
	{
	    ll n,x ;
	    string str ;
	    cin>>str ;
	    n = str.length() ;
	    ll forwrd[n]={0}, back[n]={0}, num=0 ;
	    vector<pair<ll,ll> > vect ;
	    for(int i=0;i<n;i++)
	    {
	        if((int)str[i]>47 && (int)str[i]<58 )
	        {
	            int e = (int)str[i]-48 ;
	            //forwrd[i] = back[i] = e ;
	            num++ ;
	            vect.push_back(make_pair(i,e)) ;
	        }
	    }
	    if(num==0 || num==1)
	    {
	        cout<<"safe"<<endl ;
	        continue ;
	    }
        long long int flag=0;
	    for(int i=0;i<num;i++)
	    {
	        pair<ll,ll> p = vect[i] ;
	        
	        if(i>0 && i<=num-1 )
	        {
                
	            pair<ll,ll> p1 = vect[i-1] ;
	            //pair<ll,ll> p2 = vect[i-1] ;
	            if( (p.second + p1.second)>(p.first - p1.first - 1) )
	            {
	                cout<<"unsafe"<<endl;
	                flag=1;
                    break ;
	            }
	        }
	    }
        if(flag==0){
            cout<<"safe"<<endl;
        }
	}	
	return 0;
}