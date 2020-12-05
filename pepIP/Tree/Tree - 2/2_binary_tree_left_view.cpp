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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

        if (root == nullptr) cout << 0 << '\n';
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int size1 = size;
            while (size--) {
                TreeNode* rem = q.front();
                if (size1 == size+1) cout << rem->val << ' '; 
                q.pop();
                if (rem->left != nullptr) {
                    q.push(rem->left);
                }
                if (rem->right != nullptr) {
                    q.push(rem->right);
                }
            }
        }
    
    return 0;
}
