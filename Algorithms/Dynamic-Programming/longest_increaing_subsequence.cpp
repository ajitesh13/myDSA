// to find the length of the longest subsequence pf a given sequence such
// that all elements of the subsequence are sorted in increasing order
// length of LIS{10,22,9,33,21,50,41,60,80}=6 LIS={10,22,33,50,60,80}


#include<bits/stdc++.h>
using namespace std;


int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1;

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ){
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
            }
        }
	}
	// Return maximum value in lis[]
	return *max_element(lis, lis+n);
} 

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}
