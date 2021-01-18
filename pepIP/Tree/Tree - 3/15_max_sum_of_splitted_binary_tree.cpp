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

int totalsum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return root->val + totalsum(root->left) + totalsum(root->right);
    }
}

int ans = INT32_MIN;

int maxproduct(TreeNode* root, int sum) {
    if (root == nullptr) {
        return 0;
    } else {
        int lsum = maxproduct(root->left, sum);
        int rsum = maxproduct(root->right, sum);
        int c1 = (sum-lsum)*lsum;
        int c2 = (sum-rsum)*rsum;
        ans = max(ans, max(c1, c2));
        return root->val+lsum+rsum;
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
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    // PrintInorder(root);
    int sum =  totalsum(root);
    int a = maxproduct(root, sum);
    cout << ans << '\n';
    
    return 0;
}
