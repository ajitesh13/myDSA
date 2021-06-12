#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& v, int i) {
    int n = v.size();
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n and v[l] > v[largest]) {
        largest = l;
    }

    if (r < n and v[r] > v[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, largest);
    }
}

void heapsort(vector<int>& v) {
    int n = v.size();
    for (int i=n/2-1; i>=0; i--) {
        heapify(v, i);
    }

    for (int i=n-1; i>=0; i--) {
        swap(v[0], v[i]);
        heapify(v, i);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {4,10,3,5,1};
    heapsort(v);
    
    cout << "Sorted Array: ";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}
