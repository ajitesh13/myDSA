#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *prev;
    int front;
    int back;
    int flip;
    struct node *next;
}

void insert(int a){
    struct node *temp=malloc(sizeof(struct *node));
        temp->front=NULL;
        temp->back=NULL;
        temp-flip=NULL;
        temp->next=NULL;
    while(start=NULL){
        start=temp;
        temp->prev=start;
        temp->next=NULL;
    }
    temp->prev = 


}


int main(){
    int n, m, a;
    cin>>n>>m;
    int a[n];
    struct node *start=NULL;
    struct node *end=NULL
    for (int i=0;i<n;i++{
        struct node *temp=malloc(sizeof(struct *node));
        struct node *previous;
        temp->prev=NULL;
        temp->next=NULL;
        cin>>temp->front;
        if (start==NULL){
            start=temp;
            temp->prev=start;
            end=temp;
            temp->next=end;
        }
        else{
            temp->prev=end->prev;
            (end->prev)->next=temp;
            end=temp;
            temp->next=end;
        }
    }
    struct node *temp=start
    for (int i=0;i<n;i++{
        cin>>temp->back;
        temp=temp->next;
    }
    while(end->)

    while(m--){
        int l, r, k, a, b, c, d, x;
        cin>>x;
        if(x==1){
            cin>>l>>r;

        }
        else if(x==2){
            cin>>k;
        }
        else{
            cin>>a>>b>>c>>d;
        }
    }
}


// 

// Create a class named as student with protected attributes 
// such as stud_id and stud_mark. Take a constructor to initialize
//  these attributes. Create an array of objects for the above class
//   and initialize the attributes. The memory allocation for that array 
//   should take place at the run time. Provide appropriate method to display 
//   the initialized values.

//  With an appropriate example explain, what is the role of a copy constructor when a class contains a pointer attribute and memory allocation for such an attribute takes place at the run time?

// Create a linked list with 5 nodes. Each node contains an integer data field and a pointer to the next node. After inserting data into the nodes sort the nodes in ascending order of their respective data values and display the sorted list. Memory management for the nodes should be done dynamically with the help of new and delete operators.