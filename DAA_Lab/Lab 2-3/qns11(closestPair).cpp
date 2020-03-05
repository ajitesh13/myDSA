#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
// #define " " sp
//used to sort the pairs by second element
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}

float dist(pair<int,int>x, pair<int,int>y){
    return sqrt((x.f-y.f)*(x.f-y.f) + (x.s-y.s)*(x.s-y.s) );
}

float BruteForce(vector<pair<int,int> >x, int n){

    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(x[i], x[j]) < min)
                min = dist(x[i], x[j]);

    return min;
}


float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(vector<pair<int,int> >strip, float min){
    int size = strip.size();
    // cout<<size<<"%%"<<endl;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i+1; j < size && (strip[j].s - strip[i].s) < min; j++) {
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
        }
    }
    return min;
}


float ClosestUtil(vector<pair<int,int> >x,vector<pair<int,int> >y,int n){
    if(n < 3)
        return BruteForce(x,n);

    int mid = n/2;
    pair<int,int> p;
    p = x[mid];
    // cout<<mid<<"=="<<endl;
    vector<pair<int,int> >yl,yr;

    // for (size_t i = 0; i < n; i++) {
    //     cout<<x[i].f<<" "<<x[i].s<<endl;
    // }cout<<"%%"<<endl;
    for (size_t i = 0; i < n; i++) {

        if(y[i].f <= p.f){
            yl.pb(y[i]);
        }else{
            yr.pb(y[i]);
        }
    }
    vector<pair<int,int> >cp;
    cp.resize(n-mid);
    copy(x.begin()+mid,x.end(),cp.begin());

    float dl = ClosestUtil(x, yl, mid);
    float dr = ClosestUtil(cp, yr, n-mid);
    // cout<<"$$"<<dl<<"**"<<dr<<endl;
    float d = min(dl,dr);
    vector<pair<int,int> >strip;
    // cout<<"!!"<<d<<endl;
    for (int i = 0; i < n; i++)
        if (abs(y[i].f - p.f) < d)
            strip.pb(y[i]);

    // cout<<"##"<<min(d,stripClosest(strip, d))<<endl;
    return min(d,stripClosest(strip, d));
}

void closest(vector<pair<int,int> >x,int n){
    vector<pair<int,int> >y;
    y = x;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end(), sortbysec);

    // for (size_t i = 0; i < n; i++) {
    //     cout<<x[i].f<<" "<<x[i].s<<endl;
    // }
    // cout<<endl;
    // for (size_t i = 0; i < n; i++) {
    //     cout<<y[i].f<<" "<<y[i].s<<endl;
    // }
    cout<<"min dist:"<<ClosestUtil(x,y,n)<<endl;

}
int main(int argc, char const *argv[]) {
    vector< pair<int,int> >p;
    int n,tempx,tempy;
    cin>>n;
    for (size_t i = 0; i < n; i++) {
        cin>>tempx>>tempy;
        p.pb(mp(tempx,tempy));
    }

    closest(p,n);
    return 0;
}
