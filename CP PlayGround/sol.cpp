#include <bits/stdc++.h>
using namespace std;

bool valid_check(string s) {
    bool res = false;
    stack<char> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') st.push('(');
        else { 
            if (!st.empty()) {
                if (st.top() == '(') 
                    st.pop();
                else res = false;
            } else res = false; 
        }
    }
    return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << valid_check("())(");
	
	return 0;
}
