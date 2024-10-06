#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Time: O(n log 26) -> O(n)
    // Space: O(n)
    int leastInterval(vector<char>& tasks, int n) {
        // min first priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> nextTask;

        // create max Heap
        unordered_map<char, int> numTask;
        for (char task : tasks) {
            ++numTask[task];
        }
        for (auto it = numTask.begin(); it != numTask.end(); ++it) {
            nextTask.push_back(it->second);
        }
        numTask.clear();
        make_heap(nextTask.begin(), nextTask.end());

        int ans = 0;
        int time = 0;
        while (!nextTask.empty() || !pq.empty()) {
            if (!nextTask.empty()) {
                int currTask = nextTask[0] - 1;
                int nextTime = time + n + 1;

                pop_heap(nextTask.begin(), nextTask.end());
                nextTask.pop_back();

                if (currTask > 0) {
                    pq.push({nextTime, currTask});
                }
            }

            ++time;
            ++ans;

            while (!pq.empty() && pq.top().first <= time) {
                nextTask.push_back(pq.top().second);
                push_heap(nextTask.begin(), nextTask.end());

                pq.pop();
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int ans = sol.leastInterval(tasks, n);
    cout << ans << endl;
}