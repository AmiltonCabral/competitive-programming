#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freqs(nums.size());
        vector<int> ans(k);
        for (int num : nums) {
            count[num]++;
        }

        unordered_map<int, int>::iterator itr;
        for (itr = count.begin(); itr != count.end(); itr++) {
            freqs[itr->second].push_back(itr->first);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!freqs[i].empty() && k) {
                ans[k - 1] = freqs[i].back();
                freqs[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1};
    int k = 1;
    vector<int> ans = sol.topKFrequent(nums, k);
    cout << endl;
}