#include <bits/stdc++.h>
using namespace std;

// Time: O(2^n)
// Space: O(n)
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        if (totalSum % 2) return false;

        unordered_set<string> visited;
        bool ans = false;
        int i = 0;

        function<void(int, int, int)> dfs = [&](int i, int sa, int sb) {
            if (ans) return;
            if (i == nums.size()) {
                if (sa == sb) ans = true;
                return;
            }

            // order sa and sb, so that sa <= sb
            if (sa > sb) {
                int aux = sa;
                sa = sb;
                sb = aux;
            }

            string code = to_string(sa) + '#' + to_string(sb);
            if (visited.count(code)) return;
            visited.insert(code);

            dfs(i + 1, sa + nums[i], sb);
            dfs(i + 1, sa, sb + nums[i]);
        };

        dfs(0, 0, 0);

        return ans;
    }
};

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int num : nums) target += num;
        if (target % 2) return false;
        target /= 2;

        unordered_set<int> sums;
        sums.insert(0);

        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int> newSums;

            for (int val : sums) {
                const int newVal = val + nums[i];
                if (newVal == target) return true;

                newSums.insert(val);
                newSums.insert(newVal);
            }

            sums = newSums;
        }

        return sums.count(target);
    }
};