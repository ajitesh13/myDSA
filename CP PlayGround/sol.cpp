#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 200031;

int tests,n;
double l;
int ar[N];
double time_left[N],time_right[N];
vector<double> events;

int main() {
    freopen("in", "r", stdin);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>l;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=1;i<=n;i++){
    		time_left[i]=time_left[i-1]+(ar[i]-ar[i-1])*1.0/i;
    	}
    	time_right[n+1]=0;
    	ar[n+1]=l;
    	for (int i=n;i;--i){
    		time_right[i]=time_right[i+1]+(ar[i+1]-ar[i])*1.0/(n-i+1);
    	}
        for (int i=0; i<10; i++) cout << time_left[i] << " ";
        cout << "\n";
        for (int i=0; i<10; i++) cout << time_right[i] << " ";
        cout << "\n";
    	events.clear();
    	events.push_back(0);
    	events.push_back(0);
    	for (int i=1;i<=n;i++){
    		if (time_left[i]<time_right[i]){
    			events.push_back(time_left[i]);
    		}
    		else
    		{
    			events.push_back(time_right[i]);
    		}
    	}
    	sort(events.begin(),events.end());
    	for (int i=1;i<events.size();i++){
    		l-=(events[i]-events[i-1])*i;
    	}
        for (int i=0; i<events.size(); i++) cout << events[i] << " ";
        cout << "\n";
        cout << events.back() << "\n";
    	cout.precision(15);
    	//cout<<l<<"@"<<events.back()<<" "<<events.size()<<endl;
    	// cout<<fixed<<events.back()+l/events.size()<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}