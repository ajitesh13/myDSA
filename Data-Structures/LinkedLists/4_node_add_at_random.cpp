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

Node* add_ranpos(Node* start, int data, int pos, int mes = 0) {
    if (start == null) {
        return newNode(data);
    }
    if (pos == 0) {
        Node* ptr = start;
        start = newNode(data);
        start->link = ptr;
        return start;
    } else {
        if (mes == pos-1) {
            Node* ptr = start->link;
            start->link = newNode(data);
            (start->link)->link = ptr;
        } else {
            start->link = add_ranpos(start->link, data, pos, mes + 1);
        }
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
    Node* start;
    start = add_back(start, 12);
    start = add_back(start, 15);
    start = add_back(start, 27);
    show(start); cout << '\n';
    start = add_ranpos(start, 88, 2);
    show(start); cout << '\n';
    return 0;
}