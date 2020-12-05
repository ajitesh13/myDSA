#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        this->data = value;
        this->right = this->left = nullptr;
    }
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
                cout << curr->data << ' ';
                currp1->right = curr;
                curr = curr->left;
            } else if (currp1->right == curr) {
                currp1->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(10);
    root->right = new Node(34);
    root->left->left = new Node(2);
    root->left->right = new Node(65);
    root->right->left = new Node(11);
    root->right->right = new Node(7);

    morris(root);
    return 0;
}