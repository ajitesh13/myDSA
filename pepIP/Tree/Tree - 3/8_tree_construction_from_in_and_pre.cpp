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

TreeNode* InPre(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
    if (p1 > p2 && i1 > i2) {
        return nullptr;
    }
    TreeNode* parent = new TreeNode(preorder[p1]);
    int index = ump.find(preorder[p1])->second;
    int count = index - i1;
    parent->left = InPre(preorder, p1+1, p1+count, inorder, i1, index-1);
    parent->right = InPre(preorder, p1+count+1, p2, inorder, index+1, i2);
    return parent;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i=0; i<inorder.size(); i++) {
        if (ump.find(inorder[i]) == ump.end()) {
            ump.insert({inorder[i], i});
        }
    }
    int p1 = 0, p2 = preorder.size()-1, i1 = 0, i2 = inorder.size()-1;
    TreeNode* root = InPre(preorder, p1, p2, inorder, i1, i2);
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
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* Node = buildTree(preorder, inorder);
    PrintInorder(Node);
    
    return 0;
}
