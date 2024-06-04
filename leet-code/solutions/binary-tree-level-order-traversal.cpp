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

// Time: O(n)
// Space: O(n)
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<pair<TreeNode *, int>> qu;
        vector<vector<int>> ans;

        if (root) {
            qu.push({root, 0});
        }

        while (!qu.empty()) {
            TreeNode *curr = qu.front().first;
            int lvl = qu.front().second;
            qu.pop();

            if (ans.size() <= lvl) {
                ans.push_back({});
            }
            ans[lvl].push_back(curr->val);

            if (curr->left) {
                qu.push({curr->left, lvl + 1});
            }

            if (curr->right) {
                qu.push({curr->right, lvl + 1});
            }
        }

        return ans;
    }
};