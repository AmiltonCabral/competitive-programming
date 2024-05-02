#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& perm,
             unordered_set<int>& permSet) {
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }
        for (int num : nums) {
            if (!permSet.count(num)) {
                perm.push_back(num);
                permSet.insert(num);
                dfs(nums, perm, permSet);
                perm.pop_back();
                permSet.erase(num);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        unordered_set<int> permSet;
        dfs(nums, perm, permSet);
        return ans;
    }
};
