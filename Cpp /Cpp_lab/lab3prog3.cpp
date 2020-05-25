#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Staff
{

protected:
    int id;
    long long int phone;

public:
    void get(int id_staff, int number)
    {
        id = id_staff;
        phone = number;
    }
    void show()
    {
        cout << "ID : " << id << endl;
        cout << "PHONE NUMBER : " << phone << endl;
    }
};
class Teacher : public Staff
{
protected:
    int years_of_experience;

public:
    void get1(int yoe)
    {
        years_of_experience = yoe;
    }
    void show1()
    {
        cout << "Years of Experience : " << years_of_experience << endl;
    }
};
class Officer : public Staff
{
    protected:
        int Grade;
    void get2(int grade)
    {
        Grade = grade;
    }
    void show2()
    {
        cout << "Grade : " << Grade << endl;
    }
};
class Regular : public Teacher
{
protected:
    int Basic_pay, HRA, DA, Gross;

public:
    void get5(int pay)
    {
        Basic_pay = pay;
    }
    void calculate()
    {
        DA = 1.5 * Basic_pay;
        HRA = 0.2 * Basic_pay;
        Gross = Basic_pay + DA + HRA;
    }
    void show5()
    {
        cout << "Gross : " << Gross << endl;
    }
};

class Contract : public Teacher
{
protected:
    int pay, dur;

public:
    void contract(int p, int d)
    {
        pay = p;
        dur = d;
    }
    void show3()
    {
        cout << "Pay Consolidated : " << pay << endl;
        cout << "Contract Duration : " << dur << endl;
    }
};

int main()
{
    Regular R;
    R.get(11, 7377844652);
    R.show();
    R.get1(5);
    R.show1();
    R.get2(200);
    R.calculate();
    R.show2();
    Contract c;
    c.contract(10000, 5);
    c.show3();

    return 0;
}