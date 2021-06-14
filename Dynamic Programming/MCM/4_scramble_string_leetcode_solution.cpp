#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> ump;
bool isScramble(string s1, string s2) {
    if(s1==s2)
        return true;
        
    int len = s1.length();
    int count[26] = {0};
    for(int i=0; i<len; i++)
    {
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }
    
    for(int i=0; i<26; i++)
    {
        if(count[i]!=0)
            return false;
    }
    
    string key = s1;
    key.push_back(' ');
    key.append(s2);
    
    if (ump.find(key) != ump.end()) {
        return ump[key];
    } else {
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return ump[key] = false;   
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << isScramble("great", "rgeat") << "\n";
    
    return 0;
}
