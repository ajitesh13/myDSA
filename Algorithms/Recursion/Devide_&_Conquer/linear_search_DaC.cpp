// linear search using devide and conquer 

#include <iostream>
using namespace std;

int li_search(int a[],int p,int r,int item) {
	if(item == a[p]){
		return p;
	}else if(item == a[r]) {
		return r;
	}else{
		li_search(a,p+1,r-1,item);
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int item;
	cin >> item;
	cout << "Item found at: " << li_search(a,0,n,item) << endl;
	return 0;
}