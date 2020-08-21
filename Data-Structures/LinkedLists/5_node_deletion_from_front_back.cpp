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

Node* del_back(Node* start) {
    if (start == null || start->link == null) {
        start = null;
        return start;
    } else {
        if (start->link->link == null) {
            start->link = null;
        } 
        start->link = del_back(start->link);
    }
    return start;
}

Node* del_front(Node* start) {
    if (start == null || start->link == null) {
        start = null;
        return null;
    } else {
        start = start->link;
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
    start = add_back(start, 7);
    start = add_back(start, 18);
    show(start); cout << '\n';
    start = add_back(start, 50);
    start = add_front(start, 90);
    show(start); cout << '\n';
    start = del_back(start);
    show(start); cout << '\n';
    start = del_back(start);
    show(start); cout << '\n';
    start = del_front(start);
    show(start); cout << '\n';
    start = add_back(start, 50);
    start = add_front(start, 90);
    show(start); cout << '\n';
    start = del_front(start);
    show(start); cout << '\n';
    return 0;
}