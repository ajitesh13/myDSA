// Create a class named as student with protected attributes 
// such as stud_id and stud_mark. Take a constructor to initialize
// these attributes. Create an array of objects for the above class
// and initialize the attributes. The memory allocation for that array 
// should take place at the run time. Provide appropriate method to display 
// the initialized values.

#include <iostream>
using namespace std;

class Student{
    protected:
        int stud_id;
        int stud_mark;
    public:
        Student(){
            cout<<"Enter ID: ";cin>>stud_id;
            cout<<"Enter Mark: ";cin>>stud_mark;
        }
        void display(){
            cout<<"Student ID = "<<stud_id<<" ";
            cout<<"Student Mark = "<<stud_mark<<endl;
        }
};

int main(){
    Student *p;
    int a;
    cin>>a;
    p = new Student[a];
    for(int i=0; i<a; i++){
        p[i].display();
    }
    for(int i=0; i<a; i++){
        p[i].display();
    }
    delete[]p;
    return 0;
}