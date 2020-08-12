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

bool ispal(string str, int i, int j) {
    while (j > i) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;j--;
    }
    return true;
}

void store(vector<vector<string>>& ap, vector<string>& cp, int start, int n, string str) {
    if (start >= n) {
        ap.push_back(cp);
        return;
    } else {
        for (int i=start; i<n; i++) {
            if (ispal(str, start, i)) {
                cp.push_back(str.substr(start, i-start + 1));
                store(ap, cp, i+1, n, str);
                cp.pop_back();
            }
        }
    }
}

void ispalpart(string str) {
    int n = str.size();
    vector<vector<string>> ap;
    vector<string> cp;
    store(ap, cp, 0, n, str);
    for (int i=0; i< ap.size(); i++ ) 
    { 
        for (int j=0; j<ap[i].size(); j++) 
            cout << ap[i][j] << " "; 
        cout << "\n"; 
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
    
    string str;
    cin >> str;
    ispalpart(str);
    
    cerr << "\n\n**ET : " << tick() << "**\n";
    return 0;
}
