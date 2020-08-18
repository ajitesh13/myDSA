// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define make_pair mp
using namespace std;
const int MAX = 10e6;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void gen(string str, int n) {
    int size = pow(2, n);
    for (int i=0; i<size; i++) {
        for (int j=0; j<3; j++) {
            if (i&(1<<j)) {
                if (j == 0) {
                    cout << 'a';
                } else if (j == 1) {
                    cout << 'b';
                } else if (j == 2) {
                    cout << 'c';
                }
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    string str;
    cin >> str;
    gen(str, str.size());
    
    cerr << "\n\n**ET : " << tick() << "**\n";
    return 0;
}
