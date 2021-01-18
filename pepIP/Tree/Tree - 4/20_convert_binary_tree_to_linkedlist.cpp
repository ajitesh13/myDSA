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

TreeNode* flat(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* ltail = flat(root->left);
    TreeNode* rtail = flat(root->right);
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    } else if (root->left != nullptr && root->right == nullptr) {
        TreeNode* lhead = root->left;
        root->right = lhead;
        root->left = nullptr;
        return ltail;
    } else if (root->left == nullptr && root->right != nullptr) {
        return rtail;
    } else {
        ltail->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return rtail;
    }
}
void flatten(TreeNode* root) {
    TreeNode* ignore = flat(root);
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
    PrintInorder(root);
    flatten(root);
    cout << endl;
    PrintInorder(root);
    
    return 0;
}
