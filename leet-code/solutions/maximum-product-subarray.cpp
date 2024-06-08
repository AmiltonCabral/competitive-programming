#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        long ans = nums[0];
        long minSum = 1;
        long maxSum = 1;

        for (int num : nums) {
            int currMin = min(minSum * num, maxSum * num);
            int currMax = max(minSum * num, maxSum * num);
            minSum = min(num, currMin);
            maxSum = max(num, currMax);

            ans = max(ans, maxSum);
        }

        return ans;
    }
};
