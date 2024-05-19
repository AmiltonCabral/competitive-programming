#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        vector<bool> visited(nums.size());
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            if (curr.first == nums.size() - 1) return curr.second;
            q.pop();

            int longest = curr.first + nums[curr.first];
            for (int i = curr.first + 1; i <= longest && i < nums.size(); ++i) {
                if (!visited[i]) {
                    q.push({i, curr.second + 1});
                    visited[i] = true;
                }
            }
        }

        // not necessary but required to compile
        return 0;
    }
};