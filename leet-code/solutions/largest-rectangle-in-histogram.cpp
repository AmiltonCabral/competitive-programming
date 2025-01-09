#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;  // {i,h}
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;

            while (!stk.empty() && heights[i] < stk.top().second) {
                start = stk.top().first;
                const int height = stk.top().second;
                const int currArea = height * (i - start);
                maxArea = max(maxArea, currArea);
                stk.pop();
            }

            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            const int index = stk.top().first;
            const int height = stk.top().second;
            const int currArea = height * (heights.size() - index);
            maxArea = max(maxArea, currArea);
            stk.pop();
        }

        return maxArea;
    }
};
