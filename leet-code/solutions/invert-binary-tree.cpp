#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertSubTree(root);
        }
        return root;
    }

    void invertSubTree(TreeNode* node) {
        TreeNode* aux = node->left;
        node->left = node->right;
        node->right = aux;

        if (node->left) {
            invertSubTree(node->left);
        }
        if (node->right) {
            invertSubTree(node->right);
        }
    }
};