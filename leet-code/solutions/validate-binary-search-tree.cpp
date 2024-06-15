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
    bool isValidBST(TreeNode *root) {
        bool ans = true;

        function<pair<int, int>(TreeNode *)> dfs = [&](TreeNode *node) {
            int smaller = INT_MAX;
            int bigger = INT_MIN;

            if (node->left) {
                pair<int, int> vals = dfs(node->left);
                smaller = vals.first;
                bigger = vals.second;

                if (vals.second >= node->val) {
                    ans = false;
                }
            }

            if (node->right) {
                pair<int, int> vals = dfs(node->right);
                smaller = min(smaller, vals.first);
                bigger = max(bigger, vals.second);

                if (vals.first <= node->val) {
                    ans = false;
                }
            }

            smaller = min(smaller, node->val);
            bigger = max(bigger, node->val);

            return make_pair(smaller, bigger);
        };

        dfs(root);

        return ans;
    }
};