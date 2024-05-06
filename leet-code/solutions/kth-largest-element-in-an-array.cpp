#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        while (k--) {
            pq.push(nums.back());
            nums.pop_back();
        }

        while (!nums.empty()) {
            if (pq.top() < nums.back()) {
                pq.pop();
                pq.push(nums.back());
            }
            nums.pop_back();
        }

        return pq.top();
    }
};
