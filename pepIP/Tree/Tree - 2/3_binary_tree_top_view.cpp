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

    queue<pair<TreeNode*, int>> q;
    unordered_map<int, int> ump;
    int omax = INT_MIN, omin = INT_MAX;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<TreeNode*, int> rem = q.front();
            q.pop();
            if (rem.first->left != nullptr) {
                q.push({rem.first->left, rem.second-1});
            }
            if (rem.first->right != nullptr) {
                q.push({rem.first->right, rem.second+1});
            }
            if (ump.find(rem.second) == ump.end()) {
                omax = max(omax, rem.second);
                omin = min(omin, rem.second);
                ump.insert({rem.second, rem.first->val});
            }
        }
    }

    for (int i=omin; i<=omax; i++) {
        cout << ump[i] << ' ';
    }

    return 0;
}
