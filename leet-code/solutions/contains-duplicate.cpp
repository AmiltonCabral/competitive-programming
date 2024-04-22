#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> setNums;
        for (int nums : nums) {
            setNums.insert(nums);
        }
        return setNums.size() == nums.size();
    }
};