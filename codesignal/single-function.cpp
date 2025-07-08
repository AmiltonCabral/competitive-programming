vector<int> solution(vector<int> nums) {
    vector<int>(nums.size() - 2) ans;

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] < nums[i+1] && nums[i+1] > nums[i+2]) {
            ans[i] = 1;
        } else if (nums[i] > nums[i+1] && nums[i+1] < nums[i+2]) {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
    }

    return ans;
}
