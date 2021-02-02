#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_multiset<int> st;
    st.insert(30);
    st.insert(30);
    st.insert(40);
    for (auto it=st.begin(); it!=st.end(); it++) {
        cout << *it << ' ';
    }
    
    return 0;
}
