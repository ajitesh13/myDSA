#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   std::vector<int> a={1,2,3};
   a.erase(std::find(a.begin(),a.end(),2));
   return 0;
   for(int i=0; i<3; i++){
   	cout<<a[i]<<" ";
   }
}