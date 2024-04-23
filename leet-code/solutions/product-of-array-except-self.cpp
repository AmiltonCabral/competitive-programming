#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int sum = 1;
        for (int i = 1; i < nums.size(); i++) {
            sum *= nums[i - 1];
            ans[i] = sum;
        }
        sum = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            sum *= nums[i + 1];
            ans[i] *= sum;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 1, 0, -3, 3};
    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);
    cout << endl;
}