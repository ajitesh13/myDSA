#include <bits/stdc++.h>
using namespace std;

void showpq (priority_queue<int, vector<int>, greater<int>> p) {
    priority_queue<int, vector<int>, greater<int>> q = p;
    while (!q.empty()) {
        cout << q.top();
        q.pop();
        cout << " ";
    }
    cout << '\n';
}

int main() {
    priority_queue<int> p; // for making max-head
    // priority_queue<int, vector<int>, greater<int>> p; // for making min heap 
    p.push(10);
    p.push(30);
    p.push(20);
    p.push(5);
    p.push(1);
    showpq(p);
    cout << "Size: " << p.size() << '\n';
    cout << "Top: " << p.top() << '\n';
    p.pop();
    showpq(p);
    return 0;
}