#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int subSum = nums[0];
        int n = nums.size();
        int ans = subSum >= target ? 1 : n + 1;
        int l = 0;
        int r = 0;
        bool foundAns = subSum >= target ? true : false;

        while (l <= r) {
            if (subSum <= target) {
                ++r;
                if (r == n) break;
                subSum += nums[r];
            } else {
                subSum -= nums[l];
                ++l;
                if (l > r) break;
            }

            cout << l << ' ' << r << endl;
            cout << subSum << ' ' << ans << endl << "----" << endl;

            // check if found a better ans
            if (subSum >= target && r - l + 1 < ans) {
                ans = r - l + 1;
                foundAns = true;
            }
        }

        return foundAns ? ans : 0;
    }
};

// [_,_,x,x,x,x,_,_]
// [x,x,x,x,x,x,x,x]
// [0,1,2,3,4,5,6,7]