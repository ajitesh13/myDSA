// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
#define MAX 10e5
//#define MAX 10e4
using namespace std;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void printcomb(char* input, int in, char* output, int out) {
    if (input[in] == '\0') {
        output[out] = '\0';
        cout << output << '\n';
        return;
    }
    output[out] = input[in];
    output[out + 1] = ' ';
    printcomb(input, in+1, output, out + 2);
    if (input[in + 1] != '\0') {
        printcomb(input, in+1, output, out+1);
    }
    

}

// int main() {
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    char input[] = "1214";
    char *output = new char[100];
    output[0] = '\0';
    printcomb(input, 0, output, 0);
     
    cerr << "\n\n**ET : " << tick() << "**\n";
    return 0;
}
