#include <bits/stdc++.h>
using namespace std;

// Time:  O(n)
// Space: O(n)
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); ++i) {
            // before
            if (newInterval[1] < intervals[i][0]) {
                result.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(),
                     back_inserter(result));
                return result;
            }
            // after
            if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            }
            // overlapping
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {5, 8}};
    vector<int> newInterval = {3, 5};

    vector<vector<int>> result = sol.insert(intervals, newInterval);
    cout << endl;
}