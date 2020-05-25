#include <bits/stdc++.h>
using namespace std;

int main(){
	//unsigned long long int n = 10000000001;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <int> vect1;
		vector <int> vect2;
		vector <int>::iterator iter;
		int b;
		for(int i=0; i<n; i++){
			cin>>b;
			vect1.push_back(b);
			vect2.push_back(b);
		}
		sort(vect2.begin(), vect2.end());
		int large = vect2[n-1];
		//cout<<large<<endl;
		iter = find(vect1.begin(), vect1.end(), large);
		int index = distance(vect1.begin(), iter);
		//cout<<index<<endl;
		int sum=0;
		int cost=0;
		int cntr=1;
		int pivot=large;
		for(int i=0; i<n-1; i++){
			//pivot = large;
			//if(vect1[index] > pivot){
			//	pivot = vect1[index];
			//}
			if(vect[i]>vect[i+1])
			if(pivot > vect1[i+1]){
				cost = (pivot+cntr)-vect1[i+1];
				sum = cost+sum;
				//cout<<sum<<" ";
				cntr++;
			}
		}
		//cout<<endl;
		cout<<sum<<endl;
	}
	return 0;
}