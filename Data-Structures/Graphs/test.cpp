#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <random>
#include <ctime>
#include <chrono>
 
using namespace std;
 
long long t, n, m, u, v, q, k, p, l, r;
const int N = 1e6 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
 
long long arr[N], L[N], R[N], cnt[N];
int tree[N];
 
void subtract(int x, int n) {
  while (x <= n) {
    tree[x]--;
    x += (x & -x);
  }
}
 
void add(int x, int n) {
  while (x <= n) {
    tree[x]++;
    x += (x & -x);
  }
}
 
int sum(int x) {
  int ret = 0;
  while (x) {
    ret += tree[x];
    x -= (x & -x);
  }
  return ret;
}
 
int findMex(int n) {
  int lo = 1, hi = n + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (sum(mid) == mid) lo = mid + 1;
    else hi = mid;
  }
  return lo - 1;
}
 
void addVal(int x) {
  cnt[x]++;
  if (cnt[x] == 1) add(x + 1, n);
}
 
void delVal(int x) {
  cnt[x]--;
  if (cnt[x]==0) subtract(x + 1, n);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    vector <int> sol;
    for (int i = 0; i <= n + 1; ++i) tree[i] = cnt[i] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      addVal(arr[i]);
    }
    for (int i = 1; i <= n; ++i) {
      while (arr[i] != i - 1) {
        int nextVal = findMex(n);
        if (nextVal != n) {
          delVal(arr[nextVal + 1]);
          addVal(nextVal);
          arr[nextVal + 1] = nextVal;
          sol.push_back(nextVal + 1);
        } else {
          delVal(arr[i]);
          arr[i] = nextVal;
          sol.push_back(i);
          addVal(nextVal);
        }
      }
    }
    
    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); ++i) {
      cout << sol[i] << " ";
    }
    cout << '\n';
  }
}