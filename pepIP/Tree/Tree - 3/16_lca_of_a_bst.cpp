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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (true) {
        if (p->val < root->val && q->val > root->val) {
            break;
        } else if (p->val > root->val && q->val < root->val) {
            break;
        } else if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else if (root->val == p->val || root->val == q->val) {
            break;
        }
    }
    return root;
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
    cout << lowestCommonAncestor(root, root->left->left, root->left)->val << '\n';
    
    return 0;
}
