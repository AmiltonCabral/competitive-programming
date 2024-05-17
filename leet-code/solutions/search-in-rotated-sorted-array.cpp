#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        l = 0;
        r = nums.size() - 1;
        this->target = target;

        return binarySearch(nums);
    }

   private:
    int l, r, target;
    int binarySearch(vector<int>& nums) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (l >= r) return -1;

        // left ordered ?
        if (nums[l] <= nums[mid]) {
            // between left ?
            if (target >= nums[l] && target < nums[mid]) {
                // go left
                r = mid - 1;
            } else {
                // go right
                l = mid + 1;
            }

            // right ordered ?
        } else {
            // between right ?
            if (target <= nums[r] && target > nums[mid]) {
                // go right
                l = mid + 1;
            } else {
                // go left
                r = mid - 1;
            }
        }

        return binarySearch(nums);
    }
};

int main() {
    // [4,5,6,7,8,1,2,3]      target = 8
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = sol.search(nums, target);
    cout << ans << endl;
}
