#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchBt(vector<int>& nums, int target, int l, int r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (l >= r) return -1;
        if (target > nums[mid]) {
            return searchBt(nums, target, mid + 1, r);
        } else {
            return searchBt(nums, target, l, mid - 1);
        }
    }

    int search(vector<int>& nums, int target) {
        return searchBt(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    int target = 2;
    vector<int> nums = {-1};
    int ans = sol.search(nums, target);
    cout << ans << endl;
}