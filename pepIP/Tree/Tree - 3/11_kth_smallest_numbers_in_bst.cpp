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

int kthsmallest(TreeNode* root, int k) {
    vector<int> res;
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // cout << curr->val << ' ';
            res.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* currp1 = curr->left;
            while (currp1->right != nullptr && currp1->right != curr) {
                currp1 = currp1->right;
            }
            if (currp1->right == nullptr) {
                currp1->right = curr;
                curr = curr->left;
            } else if (currp1->right == curr) {
                // cout << curr->val << ' ';
                res.push_back(curr->val);
                currp1->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return res[k-1];
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
    
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(22);
    // PrintInorder(root);
    int k = 5;
    int res = kthsmallest(root, k);
    cout << res << '\n';
    
    return 0;
}
