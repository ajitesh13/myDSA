#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

Node* MergeDLL(Node* end1, Node* end2) {
    Node* start1 = end1;
    while (start1->prev != nullptr) {
        
    }
}

void printfromstart(Node* start) {
    if (start == nullptr) {cout << '\n';return;}
    else {
        cout << start->val << ' ';
        printfromstart(start->next);
    }
}

void printfromend(Node* end) {
    if (end == nullptr) {cout << '\n';return;}
    else {
        cout << end->val << ' ';
        printfromend(end->prev);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* start1 = new Node(1);
    start1->prev = nullptr;
    start1->next = new Node(2);
    start1->next->prev = start1;
    start1->next->next = new Node(3);
    start1->next->next->prev = start1->next;
    start1->next->next->next = new Node(4);
    start1->next->next->next->prev = start1->next->next;
    Node* end1 = start1->next->next->next;
    Node* start2 = new Node(5);
    start2->prev = nullptr;
    start2->next = new Node(6);
    start2->next->prev = start2;
    start2->next->next = new Node(7);
    start2->next->next->prev = start2->next;
    start2->next->next->next = new Node(8);
    start2->next->next->next->prev = start2->next->next;
    Node* end2 = start2->next->next->next;
    Node* new_start = MergeDLL(end1, end2);
    Node* new_start1 = MergeDLL(end2, end1);

    return 0;
}
