#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<int> st = {1,2,3,4,5};
    auto it = st.end();
    while (it != st.begin()) {
        it--;
        cout << *it << " ";
    }
    
    return 0;
}
