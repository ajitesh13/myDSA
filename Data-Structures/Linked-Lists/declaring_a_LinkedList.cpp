#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
};

void addNode(){
    Node *ptr;
    ptr = new Node;
    if(start == NULL){
        start = ptr;
    }else{
        ptr = start;
        while(ptr != NULL){
            ptr = (*ptr)->next;
        }
    }
}

void printLinkedList(){
    if(start == NULL){
        cout << "LinkedList Doesn't exist" << endl;
    }else{
        Node *ptr;
        ptr = start;
        while(ptr != NULL){
            cout << (*ptr).data << " ";
            ptr = (*ptr).next;
        }
    }
}

int main(){
    Node *start;
    start = NULL;

    return 0;
}