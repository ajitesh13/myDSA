//Binery search in LL
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* newNode(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node* middle(Node* start, Node* last){
    if(start == NULL){
        return NULL;
    }
    Node* slow = start;
    Node* fast = start->next;
    while(fast != last){
        fast = fast->next;
        if(fast != last){
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    return slow;
}

Node* BS(Node* head, int value){
    Node* start = head;
    Node* last = NULL;
    do{
        Node* mid = middle(start, last);

        if(mid == NULL){
            return NULL;
        }

        if(mid->data == value){
            return mid;
        }else if(mid->data < value){
            start = mid->next;
        }else{
            last = mid;
        }
    }while(last == NULL || last != start);
    return NULL;
}

int main(){
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    int value = 3;
    if(BS(head, value) == NULL){
        cout << "Value not present" << endl;
    }else{
        cout << "Present" << endl;
    }
    return 0;
}
