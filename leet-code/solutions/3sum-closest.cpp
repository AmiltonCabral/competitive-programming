#include <vector>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        int closestDiff = abs(closest - target);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                const int sum = nums[i] + nums[l] + nums[r];
                const int diff = abs(sum - target);
                if (diff < closestDiff) {
                    closest = sum;
                    closestDiff = abs(closest - target);
                }

                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    return closest;
                }
            }
        }

        return closest;
    }
};