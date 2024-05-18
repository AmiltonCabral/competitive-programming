#include <bits/stdc++.h>
using namespace std;

// Time: O(n); Space: O(1)
class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one = cost.back();
        int two = cost[cost.size() - 2];

        for (int i = cost.size() - 3; i >= 0; --i) {
            int aux = two;
            two = cost[i] + min(one, two);
            one = aux;
        }

        return min(one, two);
    }
};
