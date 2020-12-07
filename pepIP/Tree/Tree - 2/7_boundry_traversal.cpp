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

void leftboundry(TreeNode* root, set<int>& res) {
    if (root->left == nullptr) {
        return;
    }
    res.insert(root->val);
    if (root->left != nullptr) {
        leftboundry(root->left, res);
    } else {
        leftboundry(root->right, res);
    }
    
}

void rightboundry(TreeNode* root, set<int>& res) {
    if (root->right == nullptr) {
        return;
    }
    
    if (root->right != nullptr) {
        rightboundry(root->right, res);
    } else {
        rightboundry(root->left, res);
    }
    res.insert(root->val);
}

void morris(TreeNode* root, set<int>& res) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->val << ' ';
            if (curr->left == nullptr && curr->right == nullptr) {
                res.insert(curr->val);
            }
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
                if (curr->left == nullptr && curr->right == nullptr) {
                    res.insert(curr->val);
                }
                currp1->right = nullptr;
                curr = curr->right;
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(10);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);
    root->right->left->right = new TreeNode(12);
    root->right->left->left = new TreeNode(14);
    root->right->right->right = new TreeNode(9);

    // ========================================================================================================== //

    set<int> st;
    leftboundry(root, st);
    vector<int> leaf;
    morris(root, st);
    vector<int> right;
    rightboundry(root, st);
    for (auto it=st.begin(); it!=st.end(); it++) {
        cout << *it << ' ';
    }
    // code is incomplete make the order right

    // ========================================================================================================== //


    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
