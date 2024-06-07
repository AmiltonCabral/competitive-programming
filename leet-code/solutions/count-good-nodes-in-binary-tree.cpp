#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int goodNodes(TreeNode *root) {
        int ans = 0;

        function<void(TreeNode *, int)> dfs = [&](TreeNode *curr, int greater) {
            if (greater <= curr->val) {
                ++ans;
            }
            if (curr->left) {
                dfs(curr->left, max(greater, curr->left->val));
            }
            if (curr->right) {
                dfs(curr->right, max(greater, curr->right->val));
            }
        };

        dfs(root, root->val);
        return ans;
    }
};