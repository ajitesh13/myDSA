#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head;

void createNode(int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void printLL(){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

}

int main(){
    createNode(1);
    createNode(5);
    createNode(7);
    printLL();
    cout << endl;
    return 0;
}