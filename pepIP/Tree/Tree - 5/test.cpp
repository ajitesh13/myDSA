#include <stdio.h>
#include <iostream>
typedef unsigned long long ull;
const int MAX=1000001;
ull a[MAX],tree[MAX]={0},res;
int N,Q,k,p,q;
char M;
using namespace std;
void update(int p,int q)//updates the value in O(logn)
{
    while(p<=N)
    {
        tree[p]+=q;
        p+=p&(-p);
    }
 
 
}
ull getSum(int n)//gives sum till n in O(logn)
{
    ull r=0;
    while(n>0)
    {
        r+=tree[n];
        n-=n&(-n);
    }
    return r;
}
int main()
{
    cin>>N>>Q;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    for (int i=1; i<=N; i++) {
        cout << a[i];
    }
    while(Q--)
    {
        cin>>M;
        cin>>p>>q;
        p++;
       // q can be the value(while updating) q can be index p to q sum
        if(M=='T')
        {
            update(p,-q);
 
        }
        else if(M=='G')
        {
            update(p,q);
        }
        else
        {
            //i have to add 1 to q as we are using 1 based indexing
            q++;
            if(p!=1)
                res=getSum(q)-getSum(p-1);
            else
                res=getSum(q);
            cout<<res<<endl;
        }
    }
}