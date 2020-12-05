#include <bits/stdc++.h>
using namespace std;

struct Node{
// public:
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

void morris(Node* root) {
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->data << ' ';
            curr = curr->right;
        } else {
            Node* currp1 = curr->left;
            while (currp1->right != nullptr && currp1->right != curr) {
                currp1 = currp1->right;
            }
            if (currp1->right == nullptr) {
                currp1->right = curr;
                curr = curr->left;
            } else if (currp1->right == curr) {
                cout << curr->data << ' ';
                currp1->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    morris(root);
    return 0;
}