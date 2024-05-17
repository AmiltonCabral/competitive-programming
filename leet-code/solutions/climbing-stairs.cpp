#include <bits/stdc++.h>
using namespace std;

// Time: O(n); Space: O(n)
class Solution {
   public:
    int dpmap[46];

    int climbStairs(int n) {
        dpmap[0] = 1;
        dpmap[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dpmap[i] += dpmap[i - 1] + dpmap[i - 2];
        }

        return dpmap[n];
    }
};
