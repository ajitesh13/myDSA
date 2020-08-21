#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
    public:
    int data;
    Node* link;
};
Node* start = null;

void add_back(int data) {
    Node* temp = new Node;
    temp->link = null;
    temp->data = data;
    if (start == null) {
        start = temp;
    } else {
        Node* ptr = start;
        while (ptr->link != null) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void add_front(int data) {
    Node* ptr = start;
    Node* temp = new Node;
    temp->data = data;
    temp->link = ptr;
    start = temp;
}

void show() {
    Node* ptr = start;
    while (ptr != null) {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    return;
}

int main() {
    add_back(2);
    add_back(3);
    add_back(5);
    show(); cout << '\n';
    add_front(8);
    show();
    cout << '\n';
    return 0;
}