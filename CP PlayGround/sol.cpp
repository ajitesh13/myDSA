#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;
 
const int maxn = 3e5 + 5;
 
int t, n, a[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int cases = 0; cases < t; cases++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int good = 0;
        for(int i = 1; i < n; i++)
            if(a[i] > a[i - 1])
                good = 1;
        if(good)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} 