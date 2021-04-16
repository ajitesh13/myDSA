// Given an array and a size k, out put the maximum sum of any subarray of size k 

#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v  = {25,126,6,208};
    int size = 2;

    int i = 0, j = size-1;
    int sum = 0;
    for (int i=0; i<=j; i++) sum += v[i];
    int omax = sum;
    while (j < v.size()) {
        j++;
        if (j == v.size()) break;
        sum += v[j];
        sum -= v[i];
        i++;
        omax = max(omax, sum);
    }
    cout << omax << "\n";
    
    return 0;
}

