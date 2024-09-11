#include <bits/stdc++.h>
using namespace std;

// only use constant space
// not modify the vector
class Solution {
   public:
    // time: O(n^2), space: O(1)
    int findDuplicateV1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return nums.back();
    }

    // Floyd’s cycle finding algorithm
    // time: O(n), space: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (nums[slow] != nums[fast]);

        slow = 0;

        while (nums[slow] != nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return nums[slow];
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;
}