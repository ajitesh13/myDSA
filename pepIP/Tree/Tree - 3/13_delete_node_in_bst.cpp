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

TreeNode* Delete(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return nullptr;
    } else if (root->left == nullptr && root->right != nullptr) {
        return root->right; 
    } else if (root->left != nullptr && root->right == nullptr) {
        return root->left;
    } else {
        TreeNode* root1 = root->right;
        while (root1->left != nullptr) {
            root1 = root1->left;
        }
        root1->left = root->left;
        return root->right;
    }
}

TreeNode* SearchandDelete(TreeNode* root, int search) {
    if (root == nullptr) {
        return nullptr;
    } else {
        if (root->val < search) {
            root->right = SearchandDelete(root->right, search);
        } else if (root->val > search) {
            root->left = SearchandDelete(root->left, search);
        } else {
            return Delete(root);
        }
        return root;
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
    
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(25);
    root->left->left = new TreeNode(13);
    root->left->right = new TreeNode(37);
    root->left->right->left = new TreeNode(30);
    root->left->right->right = new TreeNode(43);
    int key = 37;
    PrintInorder(root);
    cout  << endl;
    TreeNode* res = SearchandDelete(root, key);
    PrintInorder(res);
    
    return 0;
}
