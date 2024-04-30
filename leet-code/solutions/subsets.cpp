#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    void bt(vector<int>& nums, vector<bool> subMarks, int i) {
        if (i == nums.size()) {
            vector<int> sub;
            for (int j = 0; j < nums.size(); j++) {
                if (subMarks[j]) {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        } else {
            bt(nums, subMarks, i + 1);
            subMarks[i] = true;
            bt(nums, subMarks, i + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> subMarks(nums.size());
        bt(nums, subMarks, 0);
        return ans;
    }
};

class Solution2 {
   public:
    vector<vector<int>> ans;
    void bt(vector<int>& nums, vector<int> sub, int i) {
        if (i == nums.size()) {
            ans.push_back(sub);
        } else {
            bt(nums, sub, i + 1);
            sub.push_back(nums[i]);
            bt(nums, sub, i + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        bt(nums, sub, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);
    cout << endl;
}