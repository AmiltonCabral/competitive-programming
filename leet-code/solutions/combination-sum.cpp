#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int target;
    vector<int> sub;
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int sum, int i) {
        if (sum == target) ans.push_back(sub);
        if (sum >= target || i >= candidates.size()) return;

        sub.push_back(candidates[i]);
        dfs(candidates, sum + candidates[i], i);

        sub.pop_back();
        dfs(candidates, sum, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        dfs(candidates, 0, 0);
        return ans;
    }
};