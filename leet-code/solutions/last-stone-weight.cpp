#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (y != x) {
                pq.emplace(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};