#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long int
#define all(x) begin(x), end(x)
#define mpi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define si set<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vs vector<string>
#define pri priority_queue<int>
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define Ford(i, a, b) for (int i = a; i >= b; i--)
#define Rep(i, x, y) for (int i = x; i <= y; i++)
#define mem(a, b) memset(a, b, sizeof(a))
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
 
double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}
 
inline ll read()
{
    ll f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
 
ll fastExpo(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = res * a;
        n /= 2;
        a = a * a;
    }
    return res;
}
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
int a[100];
int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        int f = 0;
        For(i, n) cin >> a[i];
        sort(a, a + n);
        For(i, n - 1)
        {
            if (a[i + 1] - a[i] > 1)
            {
                cout << "NO\n";
                f = 1;
                break;
            }
        }
        if (!f)
            cout << "YES\n";
    }
    cerr << "execution time is: " << tick() << "\n";
}
