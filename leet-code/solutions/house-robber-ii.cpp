#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int rob1 = nums[0];
        int rob2 = max(nums[0], nums[1]);

        // remove last
        for (int i = 2; i < nums.size() - 1; ++i) {
            int aux = rob2;
            rob2 = max(rob2, rob1 + nums[i]);
            rob1 = aux;
        }

        int firstAns = rob2;

        rob1 = nums[1];
        rob2 = max(nums[1], nums[2]);

        // remove first
        for (int i = 3; i < nums.size(); ++i) {
            int aux = rob2;
            rob2 = max(rob2, rob1 + nums[i]);
            rob1 = aux;
        }

        return max(firstAns, rob2);
    }
};
