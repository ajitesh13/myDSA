#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(int argc, char const *argv[]) {

    int n;
    cin>>n;
    vector<int>res,restemp;
    res.pb(1);

    while(res.size()<n){
        int temp = res.size();
        for (size_t i = 0; i < temp; i++) {
            restemp.pb(2*res[i]-1);
        }

        for (size_t i = 0; i < temp; i++) {
            restemp.pb(2*res[i]);
        }
        res = restemp;
        restemp.clear();
    }

    for (size_t i = 0; i < res.size(); i++) {
        if(res[i]<=n)cout<<res[i]<<" ";
    }cout<<endl;
    return 0;
}
