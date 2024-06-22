#include <bits/stdc++.h>
using namespace std;

// Time: O(n log n)
// Space: O(1)
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return a[0] < b[0]; });

        int numRemoved = 0;
        vector<int> prev = intervals[0];

        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            vector<int> curr = intervals[i];

            if (curr[0] >= prev[1]) {
                prev = curr;
                continue;
            }

            if (curr[1] < prev[1]) {
                prev = curr;
            }

            ++numRemoved;
        }

        return numRemoved;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int ans = sol.eraseOverlapIntervals(intervals);
    cout << ans << endl;
}
