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

class Solution {
   public:
    int bt(TreeNode *node, bool &isBal) {
        if (!node) return 0;
        if (!isBal) return 0;

        int lenLeft = bt(node->left, isBal);
        int lenRight = bt(node->right, isBal);

        if (abs(lenLeft - lenRight) > 1) isBal = false;

        return 1 + max(lenLeft, lenRight);
    }

    bool isBalanced(TreeNode *root) {
        bool ans = true;
        bt(root, ans);
        return ans;
    }
};