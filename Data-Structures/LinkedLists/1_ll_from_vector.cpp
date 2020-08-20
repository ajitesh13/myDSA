#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* link;
};
Node* start = NULL;

void ab(int data) {
    Node temp;
    temp.data = data;
    temp.link = NULL;
    if (start == NULL) {
        start = &temp;
        cout << "YES" << " ";
    } 
    else {
        Node* ptr;
        ptr = start;
        while (ptr != NULL) {
            ptr = ptr->link;
        }
        ptr = &temp;
    }
    cout << start->data << " "; // for printing the data of start
}

void gen(vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        ab(v[i]);
    }
}

void show() {
    Node* ptr = start;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->link;
    } 
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    gen(v);
    // show();
    return 0;
}