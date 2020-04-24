// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
// #define int long long
using namespace std;

int main() {
// signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'A'||s[i] == 'O'||s[i] == 'Y'||s[i] == 'E'||s[i] == 'U'||s[i] == 'I'||s[i] == 'a'||s[i] == 'o'||s[i] == 'y'||s[i] == 'e'||s[i] == 'u'||s[i] == 'i') {
            for (int j = i+1; j<s.length(); j++) {
                s[i] = s[j];
            }
        } else {
            s[i] = tolower(s[i]);
            s[i-1] = '.';
        }
    }

    cout << s << "\n";


    return 0;
}
