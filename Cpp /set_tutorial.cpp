#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    
    s.insert(1); // O(log n) time to insert a number  
    s.insert(2);
    s.insert(-1);
    s.insert(-10);
    
    for(int x: s){ // -10 -1 1 2 
        cout << x << " ";
    }
    cout << endl;
    
    auto it = s.find(-1);
    
    if(it == s.end()){
        cout << "Not Present\n";
    }
    else{
        cout << "Present\n";
    }

    auto it2 = s.upper_bound(-1); 

    auto it3 = s.upper_bound(0); 

    cout << *it2 << endl <<*it3 << endl;

    auto it4 = s.upper_bound(2);

    if(it4 == s.end()){
        cout << "Not Found!" << endl;
    }

    s.erase(1); // erase the element 1 and set is rearranged

    for(int x: s){
        cout << x << " ";
    }
    cout << endl;

    set< pair<int, int> > S; //declaring set of pairs

    S.insert({401, 450});
    S.insert({10, 20});
    S.insert({2, 3});
    S.insert({30, 400});

    pair<int, int> current = {40, 80};

    cout << current.first << " "; //40
    cout << current.second << endl; //80


    return 0;
}

