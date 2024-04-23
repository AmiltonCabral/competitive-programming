#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int count, ans = 0;
        unordered_set<int> numsSet;
        for (int num : nums) {
            numsSet.insert(num);
        }
        for (int num : nums) {
            if (!numsSet.count(num - 1)) {
                count = 1;
                numsSet.erase(num);
                while (numsSet.count(num + count)) {
                    numsSet.erase(num + count);
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums) << endl;
}