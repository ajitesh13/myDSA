#include <bits/stdc++.h>
using namespace std;

vector<int> segment;
int segmentsize;
vector<int> v;

void construct(vector<int> v, int index, int lo, int hi) {
    if (lo == hi) {
        segment[index] = v[lo];
        return; 
    } 
    int mid = lo + (hi-lo)/2;
    construct(v, 2*index, lo, mid);
    construct(v, 2*index+1, mid+1, hi);
    segment[index] = segment[2*index] + segment[2*index+1];
}

void update(int index, int lo, int hi, int update_index, int delta) {
    if (update_index > hi || update_index < lo) {
        return;
    }
    if (lo == hi && lo == update_index) {
        v[update_index] += delta;
        segment[index] += delta;
        return;
    }
    int mid = lo + (hi-lo)/2;
    update(2*index, lo, mid, update_index, delta);
    update(2*index+1, mid+1, hi, update_index, delta);
    segment[index] = segment[2*index] + segment[2*index+1];
}

int query(int l, int r, int index, int lo, int hi) {
    if (l <= lo && r >= hi) {
        return segment[index];
    } else if (l > hi || r < lo) {
        return 0;
    }
    int mid = lo + (hi-lo)/2;
    int temp1 = query(l,r,2*index,lo,mid);
    int temp2 = query(l,r,2*index+1, mid+1, hi);
    return temp1 + temp2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 6;
    v = {1,3,2,-5,6,4};
    segmentsize = 2*pow(2, ceil(log2(v.size())))-1 ;
    segment.assign(segmentsize+1, 0);
    int lo = 0, hi = v.size()-1, index = 1;
    construct(v, index, lo, hi);
    int l = 0, r = 2; // query are 0 based indexing
    index = 1;
    cout << query(l, r, index, lo, hi) << '\n';
    update(index, lo, hi, 0, 1);
    cout << query(l, r, index, lo, hi) << '\n';
    return 0;
}
