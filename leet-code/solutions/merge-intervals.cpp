#include <bits/stdc++.h>
using namespace std;

// Time: O(n log n)
// Space: O(n)
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

        vector<vector<int>> ans = {intervals[0]};

        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};