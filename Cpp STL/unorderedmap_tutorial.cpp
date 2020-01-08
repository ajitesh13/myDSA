#include <iostream>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char, int> M;
    unordered_map<char, int> U;

    string s = "Ajitesh Panda";
    // add(key, value) - log(N) for om , O(1) for um
    // erase(key) - logN for om, O(1) for um
    for(char c: s) M[c]++; //O(NlogN) N=|s|
    for(char c: s) U[c]++; // O(N)

    /*
    map makes a bst internally to store the keys, unordered map 
    make a hash function internally
    
    so to insert a new key the map has to traverse the full length 
    of the tree in worst case and that is log N, thats why add 
    add operation takes log N time
    */

    return 0;
}