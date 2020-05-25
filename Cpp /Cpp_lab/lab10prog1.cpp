#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream obfile;
    string name;
    int code;
    double price;
    obfile.open("invoice.txt", ios::in | ios::app);
    for(int i=0; i<2; i++)
    {
        cout << "Enter Your Name: ";cin >> name;
        cout << "Enter The Code: "; cin >> code;
        cout << "Enter The Price: "; cin >> price;
        while(obfile >> name >> code >> price){
            obfile << name << "\t" << code << "\t" << price << "\n";
        }
    }
    // obfile.close();
    // obfile.open("invoice.txt", ios::out);
    while(obfile >> name >> code >> price){
        cout << name << " " << code << " " << price << " " << endl;
    }
    obfile.close();
    return 0;
}