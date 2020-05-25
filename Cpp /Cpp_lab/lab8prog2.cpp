// // 2.       Write a program which contains
//              a generic function that can arrange 
//              elements of an array in ascending order.

#include <iostream>
using namespace std;

template <class T>
void my_sort(T a[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    my_sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
