#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets;

    void dfs(vector<int>& nums, int i, vector<int>& subset) {
        if (i >= nums.size()) {
            subsets.push_back(subset);
            return;
        }

        int ii = i;
        while (ii < nums.size() && nums[ii] == nums[i]) ++ii;

        dfs(nums, ii, subset);
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset);
        subset.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(nums, 0, subset);
        return subsets;
    }
};