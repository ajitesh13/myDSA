// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define make_pair mp
using namespace std;
const int MAX = 10e6;
int res;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

void gen(string str, int index = -1, string curr="") {
    if (index == str.size()) {
        return;
    }
    res++;
    cout << res << ":" +  curr << '\n';
    for (int i = index + 1; i < str.size(); i++) {
        curr += str[i];
        gen(str, i, curr);
        curr.erase(curr.size()-1);
    }
    return;
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
    gen(str);
    
    cerr << "\n**ET : " << tick() << "**\n";
    return 0;
}
