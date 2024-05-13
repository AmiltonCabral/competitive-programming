#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bs(vector<int>& nums, int l, int r) {
        if (l == r - 1) return min(nums[l], nums[r]);
        if (l == r) return nums[l];
        int mid = (l + r) / 2;
        if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        }

        if (nums[mid] > nums[r]) {
            return bs(nums, mid + 1, r);
        } else {
            return bs(nums, l, mid - 1);
        }
    }

    int findMin(vector<int>& nums) { return bs(nums, 0, nums.size() - 1); }
};
