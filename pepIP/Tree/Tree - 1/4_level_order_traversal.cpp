#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    if (root == nullptr) cout << NULL << '\n';
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> v;
        while (size-- > 0) {
            TreeNode* rem = q.front();
            q.pop();
            cout << rem->val << ' ';
            if (rem->left != nullptr) {
                q.push(rem->left);
            } 
            if (rem->right != nullptr) {
                q.push(rem->right);
            }
        }
        cout << '\n';
    }
    
    return 0;
}