#include <bits/stdc++.h>
using namespace std;

// This solution use Kadane's Algorithm
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSubArray = nums[0];
        int maxLocal = maxSubArray;

        for (int i = 1; i < nums.size(); ++i) {
            maxLocal = max(nums[i], maxLocal + nums[i]);
            maxSubArray = max(maxLocal, maxSubArray);
        }

        return maxSubArray;
    }
};
