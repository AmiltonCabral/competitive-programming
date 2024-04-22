#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // this isnt the best solution. You can use two pointers method to get ans
    // on O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        for (int i = 0; i < numbers.size(); i++) {
            int requestedAmount = target - numbers[i];
            if (binary_search(numbers.begin() + i, numbers.end(),
                              requestedAmount)) {
                ans[0] = i + 1;
                ans[1] = lower_bound(numbers.begin() + i + 1, numbers.end(),
                                     requestedAmount) -
                         numbers.begin() + 1;
                return ans;
            }
        }
        return ans;
    }
};