#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Time: O(n) because tree is not balanced
// Space: O(n)
class Solution {
   public:
    int diameterOfBinaryTree(TreeNode *root) {
        this->ans = 0;
        dfs(root);
        return ans;
    }

   private:
    int ans;

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int lenLeft = dfs(root->left);
        int lenRight = dfs(root->right);

        ans = max(ans, lenLeft + lenRight);

        return 1 + max(lenLeft, lenRight);
    }
};