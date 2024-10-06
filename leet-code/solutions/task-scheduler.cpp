#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<int> getNextTaskHeap(vector<char>& tasks) {
        unordered_map<char, int> numTask;

        for (char task : tasks) {
            ++numTask[task];
        }

        vector<int> nextTasks;
        for (auto it = numTask.begin(); it != numTask.end(); ++it) {
            nextTasks.push_back(it->second);
        }

        make_heap(nextTasks.begin(), nextTasks.end());

        return nextTasks;
    }

   public:
    // Time: O(n * m log 26 ) -> O(n), m = tasks size
    // Space: O(n)
    int leastInterval(vector<char>& tasks, int n) {
        // min first priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> nextTasks = getNextTaskHeap(tasks);

        int ans = 0, time = 0;
        while (!nextTasks.empty() || !pq.empty()) {
            ++time;
            ++ans;

            if (!nextTasks.empty()) {
                int currTask = nextTasks[0] - 1;
                int nextTime = time + n;

                pop_heap(nextTasks.begin(), nextTasks.end());
                nextTasks.pop_back();

                if (currTask > 0) {
                    pq.push({nextTime, currTask});
                }
            }

            while (!pq.empty() && pq.top().first <= time) {
                nextTasks.push_back(pq.top().second);
                push_heap(nextTasks.begin(), nextTasks.end());

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