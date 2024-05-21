#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int robv1(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();

        int one = nums[0];
        int two = max(one, nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            int aux = two;
            two = max(one + nums[i], two);
            one = aux;
        }

        return max(one, two);
    }

    int robv2(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();

        nums[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }

        return max(nums[nums.size() - 2], nums.back());
    }
};