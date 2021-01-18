#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int index;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), index(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, int y) : val(x), index(y), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* res = new TreeNode();

void SearchNode(TreeNode* root, int search) {
    if (root == nullptr) {
        return;
    } else {
        if (root->val == search) {
            res = root;
            return;
        }
        SearchNode(root->left, search);
        SearchNode(root->right, search);
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
    
    TreeNode* root = new TreeNode(50, 1);
    root->left = new TreeNode(25, 2);
    root->left->left = new TreeNode(13, 3);
    root->left->right = new TreeNode(37, 4);
    root->left->right->left = new TreeNode(30, 5);
    root->left->right->right = new TreeNode(43, 6);
    root->right = new TreeNode(75, 7);
    root->right->left = new TreeNode(63, 8);
    root->right->right = new TreeNode(87, 9);
    int search = 50;
    SearchNode(root, search);
    cout << res->val << ' ' << res->index << '\n';
    
    
    return 0;
}
