#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct func {
    void x() {
        cout << "hi" << endl;
    } 
    void y() {
        cout << "hello" << endl;
    }
};

template<>
void func<int>::x() {
    cout << "Hello World!" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(2);
    // head->next->next = new ListNode(1);

    // cout << 0 << "\n";
    // try {
    //     cout << 1 << "\n";
    //     throw 10;
    //     cout << 2 << "\n";
    // } catch (double d) {
    //     cout << 3 << "\n";
    // }
    // cout << 5 << "\n";


    func<int> t;
    t.x();
    t.y();
    
    return 0;
}
