#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* link;
};

Node* start = NULL;

void ab(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->link = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        Node* ptr = start;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void gen(vector<int> v) {
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
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    gen(v);
    show();
    cout << '\n';
    return 0;
}