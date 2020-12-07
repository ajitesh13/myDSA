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

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    unordered_map<int, vector<int>> ump;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<TreeNode*, int> rem = q.front();
            q.pop();
            if (rem.first->left != nullptr) {
                q.push({rem.first->left, rem.second+1});
            }
            if (rem.first->right != nullptr) {
                q.push({rem.first->right, rem.second});
            }
            if (ump.find(rem.second) == ump.end()) {
                ump.insert({rem.second, {rem.first->val}});
            } else {
                ump[rem.second].push_back(rem.first->val);
            }
        }
    }

    for (auto it=ump.begin(); it!=ump.end(); it++) {
        cout << it->first << ": ";
        for (int i=0; i<it->second.size(); i++) {
            cout << it->second[i] << ' ';
        }
        cout << '\n';
    }

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
