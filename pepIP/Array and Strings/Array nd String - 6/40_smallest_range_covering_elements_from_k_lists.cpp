// g++ -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pp pop_back
using namespace std;

double tick() {
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

// min-heap
class comp{
public:
	bool operator() (tuple<int,int,int>& a, tuple<int,int,int>& b) {
		return get<0>(a) > get<0>(b);
	}
};

void solve() {
    int t = 1;
    // cin >> t;
    // int google_contest_count = 0;
    while(t--) {
        vector<vector<int>> nums = {{10,10},{11,11}};
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, comp> pq;
        int cmax = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            cmax = max(cmax, nums[i][0]);
            pq.push(make_tuple(nums[i][0], i, 0));
        }
        int len = INT32_MAX;
        int sp, ep;
        while (pq.size() != 1) {
            tuple<int,int,int> min = pq.top();
            int diff = cmax-get<0>(min)+1;
            if (diff < len) {
                sp = get<0>(min);
                ep = cmax;
                len = diff;
            }
            int arraynumber = get<1>(min);
            int arrayindex = get<2>(min);
            pq.pop();
            arrayindex++;
            if (arrayindex >= nums[arraynumber].size()) break;
            cmax = max(cmax, nums[arraynumber][arrayindex]);
            pq.push(mt(nums[arraynumber][arrayindex], arraynumber, arrayindex));
        }
        vector<int> res;
        if (nums.size() == 1) {
            res.push_back(nums[0][0]);
            res.push_back(nums[0][0]);
        } else {
            res.push_back(sp);
            res.push_back(ep);
        }
        cout << res[0] << ' ' << res[1] << '\n';
        // cout << "Case #" << (google_contest_count+1) << ": ";google_contest_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
    
    solve();
    
    #ifndef ONLINE_JUDGE
        cerr << "\n**ET : " << tick() << "**\n";
    #endif
    
    return 0;
}
