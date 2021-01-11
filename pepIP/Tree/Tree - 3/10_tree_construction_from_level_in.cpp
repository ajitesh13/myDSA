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

TreeNode* InLev(vector<int> levelorder, vector<int> inorder, int i1, int i2) {
    if (inorder.empty() || levelorder.empty()) {
        return nullptr;
    }
    TreeNode* parent = new TreeNode(levelorder[0]);
    int index = ump[levelorder[0]];
    vector<int> leftlevelorder, rightlevelorder;
    for (int i=0; i<levelorder.size(); i++) {
        if (ump[levelorder[i]] < index) {
            leftlevelorder.push_back(levelorder[i]);
        } else if (ump[levelorder[i]] > index){
            rightlevelorder.push_back(levelorder[i]);
        }
    }
    parent->left = InLev(leftlevelorder, inorder, i1, index-1);
    parent->right = InLev(rightlevelorder, inorder, index+1, i2);
    return parent;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& levelorder) {
    for (int i=0; i<inorder.size(); i++) {
        if (ump.find(inorder[i]) == ump.end()) {
            ump.insert({inorder[i], i});
        }
    }
    int i1 = 0, i2 = inorder.size()-1;
    TreeNode* root = InLev(levelorder, inorder, i1, i2);
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
    
    vector<int> inorder = {4, 8, 10, 12, 14, 20, 22};
    vector<int> levelorder = {20, 8, 22, 4, 12, 10, 14};
    TreeNode* Node = buildTree(inorder, levelorder);
    PrintInorder(Node);
    
    return 0;
}
