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
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        stack<TreeNode *> stk;
        stk.push(root);
        unordered_set<int> visited;

        while (!stk.empty()) {
            TreeNode *curr = stk.top();

            while (curr->left && !visited.count(curr->left->val)) {
                stk.push(curr->left);
                curr = curr->left;
            }

            visited.insert(curr->val);
            stk.pop();
            ++count;

            if (count == k) {
                return curr->val;
            }

            if (curr->right && !visited.count(curr->right->val)) {
                stk.push(curr->right);
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int k = 3;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    // int k = 2;
    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);

    int ans = sol.kthSmallest(root, k);
    cout << ans << endl;
}