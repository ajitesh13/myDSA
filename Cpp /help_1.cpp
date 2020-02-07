#include <bits/stdc++.h>
using namespace std;

int main(){
    // 1. Autokeyword

    auto a = 12; // automatically transform the datatype to int
    auto b = 1.5; // automatically float

    /*
    * Best use of the auto keyword is the use of iterators
    * for(map< string, pair< int, int > >::iterator it = m.begin(); it != m.end(); ++it){}
    * => for(auto it = m.begin(); it != m.end()l ++it){}
    */

    // 2. initialize the container by pair of {}

    pair< int, int > p = {1, 2}; // equivalent in writing make_pair(1, 2)

    // 3. Range Based for loops
    /* for(auto it = container.begin(); it != container.end(); it++){}
    * => for(auto x : container){}
    */

    // Range Based for loop for vector
    vector<int> v;
    v = {1,2,5,2};
    for(auto i: v){
        cout << i << " "; // prints "1 2 5 2"
    }

    // set
    set<int> s;
    s = {4,6,2,7,4};
    for(auto i:s){
        cout << i << " "; // prints 2 4 6 7
    }

    // deque
    deque<vector< pair< int, int > > > d;
    d = {{{3, 4}, {5, 6}}, {{1, 2}, {3, 4}}};
    for(auto i:d) {
        for(auto j: i){
            cout << j.first << ' ' << j.second << '\n';
        }
        cout << endl;
    }

    // Range based for loops cant be used for stack, queue

    // 4. C++ has inbuilt gcd function
    int res = __gcd<int>(8, 16);

    // making cin, cout as fast as scanf, printf
    ios::sync_with_stdio(0);

    // Use of global array
    // (IMPORTANT) Declaring int ar[8000000] in local scope and give segmentation fault
    // but not in global scope

    // 1 << 35 is error but 1LL<<35 is not

    // double pi = 2*acos(0.0); will give the accurate value of pi

    // sorting array: int arr[5]; sort(arr, arr+5)
    // sorting vector: vector<int> v; sort(v.begin(), v,end());

    // Lambda Functions: Nameless functions(have name but not body)
    // example: sort(vect.begin(), vect.end(),[](int a,int b){return a>b})

    // use vect.emplace_back(num) its faster than vect.push_back()
    return 0;
}