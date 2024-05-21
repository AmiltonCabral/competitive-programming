#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, comb, 0);

        return ans;
    }

   private:
    int target, sum;
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, vector<int>& comb, int i = 0) {
        if (i == candidates.size()) {
            if (sum == target) {
                ans.push_back(comb);
            }
            return;
        }

        if (sum + candidates[i] <= target) {
            comb.push_back(candidates[i]);
            sum += candidates[i];

            dfs(candidates, comb, i + 1);

            comb.pop_back();
            sum -= candidates[i];
        }

        int ni = i + 1;
        while (ni < candidates.size() && candidates[i] == candidates[ni]) {
            ++ni;
        }

        dfs(candidates, comb, ni);
    }
};