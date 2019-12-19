#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            this->next = NULL;
        }
};

void PrintList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node(1);
    second = new Node(2);
    third = new Node(3);

    head->next = second;
    second->next = third;
    PrintList(head);
    return 0;
}