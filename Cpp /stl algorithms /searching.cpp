#include <bits/stdc++.h>
using namespace std;

int compare(const void *ap, const void *bp) {
    const int *a = (int *) ap;
    const int *b = (int *) bp;
    if (*a < *b)
        return -1;
    else if(*a > *b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // binary_search()
    vector<int> v = {13,15,17,28,70};
    // cout << binary_search(v.begin(), v.end(), 17) << '\n';

    //bsearch()
    int n = 8;
    int ar[8] = {1,2,3,4,5,6,7,8};
    int key = 4;
    int *p = (int *)bsearch(&key, ar, 8, sizeof(v[0]), compare);
    if (p) {
        cout << (p-ar) << '\n';
    } else {
        cout << "Not found" << '\n';
    }
    return 0;
}
