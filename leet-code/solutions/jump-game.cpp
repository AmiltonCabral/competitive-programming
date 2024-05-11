#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: O(n^2) time complexity; O(n) memory complexity.
class SolutionBF {
   public:
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size());
        reachable[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (!reachable[i] || !nums[i]) continue;

            for (int j = i + 1; j <= i + nums[i]; ++j) {
                reachable[j] = true;
                if (j == nums.size() - 1) return true;
            }
        }

        return reachable.back();
    }
};

// Greedy Approach: O(n) time complexity; O(1) memory complexity.
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = goal - 1; i >= 0; --i) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 0};
    bool ans = sol.canJump(nums);
    cout << ans << endl;
}