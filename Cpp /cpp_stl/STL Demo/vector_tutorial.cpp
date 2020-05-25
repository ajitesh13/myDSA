#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

bool f(int x, int y){
    return (x > y);
}

int main(){
    vector<int> A = {11,2,3,14};

    cout << A[1] << endl;

    sort(A.begin(), A.end()); //O(NlogN) 2,3,11,14

    bool present = binary_search(A.begin(), A.end(), 3);//true 

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); //true

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    //vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); //>=
    auto it = lower_bound(A.begin(), A.end(), 100); //same as above 
    /*point the iterator at element at an element that is less than 
    or equal to that element(here, the first hundred) */
    
    //vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); //>
    auto it2 = upper_bound(A.begin(), A.end(), 100); //same as above 
    /*point the iteratror at element that is strictly greater than the present element 
    (here at 123)*/

    cout << *it << " " << *it2 << endl; //printing the iterator

    cout << it2 - it << endl; // 5
    /* we can perform arithmetic operations in iterators  in constant times */

    /*
    Note:- by using the line 25,26,33 we can count howmany times a specific element is 
    occuring the given sequence of numbers
    */

   sort(A.begin(), A.end(), f);

   vector<int>::iterator it3;

    for(it3 = A.begin(); it3 != A.end(); it3++){ // iterating through the vector
       cout << *it3 << " ";
    }
    cout << endl;

    for(int x: A){  //iterating through the vector
        cout << x << " ";
    }
    cout << endl;
    for(int x: A){ // didnt change the values of the vector
        x++;
        cout << x << " ";
    }
    cout << endl;
    for(int &x: A){  // iterate and update the value of the vector
        x++;
        cout << x << " ";
    }
    cout << endl;
    return 0;
}