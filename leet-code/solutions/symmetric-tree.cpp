#include <functional>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool ans = true;

        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* l, TreeNode* r) {
            if (!ans) return;
            if ((l == nullptr && r != nullptr) ||
                (l != nullptr && r == nullptr)
            ) {
                ans = false;
                return;
            }
            if (l == nullptr) return;
            if (l->val != r->val) {
                ans = false;
                return;
            }

            dfs(l->left, r->right);
            dfs(l->right, r->left);
        };

        dfs(root->left, root->right);

        return ans;
    }
};