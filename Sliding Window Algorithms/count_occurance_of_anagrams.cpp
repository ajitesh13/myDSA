#include <bits/stdc++.h>
#define printmap(ump) for(auto it = ump.begin(); it!=ump.end(); it++) cout << it->first << " " << it->second << "\n"; 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string txt = "wljfrimpmyhchzriwkbarxbgfcbceyhjugixwtbvtrehb";
    string pat = "b";

    int k = pat.size();
    unordered_map<char,int> ump1, ump2;
    for (int i=0; i<txt.size(); i++) {
        ump1.insert({txt[i], 0});
        ump2.insert({txt[i], 0});
    }
    for (int i=0; i<pat.size(); i++) {
        ump1[pat[i]]++;
    }
    for (int i=0; i<=k-1; i++) {
        ump2[txt[i]]++;
    }
    int i = 0, j = k-1, res = 0;
    while (j < txt.size()) {
        if (ump1 == ump2) res++;
        j++;
        ump2[txt[j]]++;
        ump2[txt[i]]--;
        i++;
    }
    cout << res << "\n";
    
    return 0;
}
