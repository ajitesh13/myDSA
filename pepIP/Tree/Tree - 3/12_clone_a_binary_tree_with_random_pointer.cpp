#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *random;
    TreeNode() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *random) : val(x), left(left), right(right), random(random) {}
};

void InsertNewNode(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {
        TreeNode* node = new TreeNode(root->val);
        node->left = root->left;
        root->left = node;
        InsertNewNode(root->left->left);
        InsertNewNode(root->right);
    }
}

void UpdateRandom(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {
        if (root->random != nullptr) {
            root->left->random = root->random->left;
        }
        UpdateRandom(root->left->left);
        UpdateRandom(root->right);
    }
}

TreeNode* ExtractOriginal(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* left1 = ExtractOriginal(root->left->left);
    TreeNode* right1 = ExtractOriginal(root->right);
    TreeNode* croot = root->left;
    root->left = croot->left;
    croot->left = left1;
    croot->right = right1;
    return croot;
}


void PrintInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    PrintInorder(root->left);
    // cout << root->val << ' ';
    if (root->random == nullptr) {
        cout << "[" << root->val << "," << "NULL" << "]\n"; 
    } else {
        cout << "[" << root->val << "," << root->random->val << "]\n"; 
    }
    PrintInorder(root->right);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    root->random = root->right->left;
    root->left->random = root->left->left;
    root->left->right->random = root->right;
    root->left->right->left->random = root->left->right;
    root->right->left->random = root->right->right;
    root->right->right->random = root->right->right->right;
    root->right->right->right->random = root;
    cout << "Tree 1(Before Process): \n";
    PrintInorder(root);
    InsertNewNode(root);
    UpdateRandom(root);
    TreeNode* root1 = ExtractOriginal(root);
    cout << "Tree 1(After Process): \n";
    PrintInorder(root);
    cout << "Tree 2: \n";
    PrintInorder(root1);
    
    return 0;
}
