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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty()) {
            ans.push_back(qu.back()->val);
            int quLen = qu.size();

            while (quLen--) {
                TreeNode *curr = qu.front();
                qu.pop();

                if (curr->left) {
                    qu.push(curr->left);
                }
                if (curr->right) {
                    qu.push(curr->right);
                }
            }
        }

        return ans;
    }
};