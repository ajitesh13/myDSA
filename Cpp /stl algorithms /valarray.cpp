#include <bits/stdc++.h>
using namespace std;

int main() {
    valarray<int> var = {10, 2, 20, 1, 30};
    valarray<int> var1;
    var1 = var.apply([](int x){return x = x + 5;});
    for (int &x: var1) cout << x << " ";
    cout << endl;
    cout << "sum1: " << var.sum() << endl;
    cout << "sum2L " << var1.sum() << endl;

    cout << "Max in var is: " << var.max() << '\n';
    cout << "Min in var is: " << var.min() << '\n';
    valarray<int> var2 = var.shift(2); // shift left, to shift right pass -ve argument
    for (int &x: var2) cout << x << " ";
    cout << '\n';
    var2 = var.cshift(2); // circular shift
    for (int &x: var2) cout << x << " ";
    var.swap(var2); // swapping values of 2 valarrays 
    return 0;
}