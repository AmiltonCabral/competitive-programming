#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS, sempre que passar por um adiciona a lista dos parent, ao voltar remove
// Quando encontrar P, cria uma copia da lista como um set, continua a lista
// com o BFS ate achar Q. quando achar Q, remove cada um da pilha e ve se ta
// no set, o primeiro encontrado é o LCA.
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        unordered_set<TreeNode*> ancestors;
        TreeNode* next;
        TreeNode* ans;
        bool found = false;
        bool finished = false;

        function<void(TreeNode*)> DFS = [&](TreeNode* curr) {
            if (!found && (curr == p || curr == q)) {
                for (TreeNode* node : path) {
                    ancestors.insert(node);
                }
                next = curr == p ? q : p;
                found = true;
            }

            if (found && curr == next) {
                while (!path.empty()) {
                    if (ancestors.count(path.back())) {
                        ans = path.back();
                        finished = true;
                        return;
                    }
                    path.pop_back();
                }
            }

            if (curr->left && !finished) {
                path.push_back(curr->left);
                DFS(curr->left);
                path.pop_back();
            }
            if (curr->right && !finished) {
                path.push_back(curr->right);
                DFS(curr->right);
                path.pop_back();
            }
        };

        path.push_back(root);
        DFS(root);

        return ans;
    }
};