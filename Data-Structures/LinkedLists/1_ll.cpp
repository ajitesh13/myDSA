// Complete Code for linkedlist incerstion and traversal

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

Node *start = NULL;

void add_at_end(int data){
    Node new_node;
    new_node.data = data;
    new_node.next = NULL;
    if(start == NULL){
        start = &new_node;
    }else{
        Node *ptr;
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = &new_node;
    }
}
void show_ll(){
    if(start == NULL){
        cout << "LinkedList is empty" << endl;
    }
    else{
        Node *ptr;
        ptr = start;
        while(ptr != NULL){
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}

int main(){
    add_at_end(1);
    add_at_end(2);
    add_at_end(3);
    add_at_end(4);
    show_ll();
    return 0;
}
