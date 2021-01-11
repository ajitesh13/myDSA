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

unordered_map<int,int> ump;

TreeNode* InPost(vector<int>& postorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
    if (p1 > p2 || i1 > i2) {
        return nullptr;
    }
    TreeNode* parent = new TreeNode(postorder[p2]);
    int index = ump[postorder[p2]];
    int count = i2-index;
    parent->left = InPost(postorder,p1, p2-count-1, inorder, i1, index-1);
    parent->right = InPost(postorder,p2-count, p2-1, inorder, index+1, i2);
    return parent;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i=0; i<inorder.size(); i++) {
        if (ump.find(inorder[i]) == ump.end()) {
            ump.insert({inorder[i], i});
        }
    }
    int p1 = 0, p2 = postorder.size()-1, i1 = 0, i2 = inorder.size()-1;
    TreeNode* root = InPost(postorder, p1, p2, inorder, i1, i2);
    return root;
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
    
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* Node = buildTree(inorder, postorder);
    PrintInorder(Node);
    
    return 0;
}
