#include <iostream>
#include <map>
#include <algorithm>

int main(){
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[100000232] = 1; 

    map<char, int> cnt;
    string x = "ajitesh";

    for(char c : x){
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['z'] << endl;

    //A.find(key);
    //A.erase(key);

}