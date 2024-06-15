#include <bits/stdc++.h>
using namespace std;

// Time:  O(n)
// Space: O(1)
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = INT_MIN;

        while (l < r) {
            int curr = min(height[l], height[r]) * (r - l);
            ans = max(ans, curr);

            if (height[l] > height[r]) {
                --r;
            } else {
                ++l;
            }
        }

        return ans;
    }
};