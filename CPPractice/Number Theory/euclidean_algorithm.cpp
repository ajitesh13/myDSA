#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    int temp = gcd(b, a%b);
    return temp;
}

int main() {
    int n1, n2;
    cin >> n2 >> n2;
    cout << gcd(n1, n2) << '\n';
    return 0;
}