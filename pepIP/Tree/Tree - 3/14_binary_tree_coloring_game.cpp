#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* target;
int count(TreeNode* root) {
    if (root == nullptr) return 0;
    else {
        return 1 + count(root->left) + count(root->right);
    }
}
TreeNode* search(TreeNode* root, int x) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->val == x) {
        target = root;
        return root;
    } else {
        root->left = search(root->left, x);
        root->right = search(root->right, x);
    }
    return root;
}
bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    TreeNode* ignore = search(root, x);
    int c1 = count(target->left);
    int c2 = count(target->right);
    int c3 = n - (c1+c2+1);
    if (c1 > n/2 || c2 > n/2 || c3 > n/2) {
        return true;
    } else {
        return false;
    }
}

void PrintInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    PrintInorder(root->left);
    cout << root->val << ' ';
    PrintInorder(root->right);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int n = 11, x = 3;
    cout << btreeGameWinningMove(root, n, x);
    
    return 0;
}
