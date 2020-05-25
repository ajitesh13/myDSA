// Write a C++ program to allocate memory for an array 
// of double type. The size of the array should be given by
// the user at the run time. Use new and delete operators 
// for memory allocation and deallocation.

#include <iostream>
using namespace std;

int main(){
    double *p;
    int a;
    cin>>a;
    p = new double[a];
    for(int i=0; i<a; i++){
        cout<<"Enter Number: ";cin>>p[i];
    }
    for(int j=0; j<a; j++){
        cout<<p[j]<<" ";
    }
    delete []p;
    return 0;
}
HVFHQIJscpoknk