#include <bits/stdc++.h>
using namespace std;

int rod_cutting(int total_length, vector<int> length, vector<int> price, int n) {
    if (n == 0 || total_length == 0) return 0;
    else {
        if (length[n-1] <= total_length) {
            return max(price[n-1] + rod_cutting(total_length-length[n-1], length, price, n), rod_cutting(total_length, length, price, n-1));
        } else {
            return rod_cutting(total_length, length, price, n-1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int total_length = 8;
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = price.size();
    cout << rod_cutting(total_length,length,price, n) << "\n";

    return 0;
}
