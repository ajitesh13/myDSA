#include <bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
    public:
    int data;
    Node* link;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->link = null;
    return temp;
}

Node* add_back(Node* start, int data) {
    if (start == null) {
        return newNode(data);
    } else {
        start->link = add_back(start->link, data);
        return start;
    }
}

Node* add_front(Node* start, int data) {
    if (start == null) {
        return newNode(data);
    } else {
        Node* ptr = start;
        start = newNode(data);
        start->link = ptr;
        return start;
    }
}

Node* delk(Node* start, int r, int pos = 0) {
    if (r == 0) {
        start = start->link;
        return start;
    } else if (start->link == null) {
        return start;
    } else {
        if (r-1 == pos) {
            start->link = start->link->link;
            return start;
        }
        start->link = delk(start->link, r, pos + 1);
    }
    return start;
}

void show(Node* start) {
    if (start == null) {
        return;
    } else {
        cout << start->data << " ";
        show(start->link);
    }
}

int main() {
    Node* start = null;
    start = add_back(start, 12);
    start = add_back(start, 14);
    start = add_back(start, 16);
    start = add_back(start, 18);
    show(start); cout << '\n';
    start = delk(start, 4);
    show(start); cout << '\n';
    return 0;
}