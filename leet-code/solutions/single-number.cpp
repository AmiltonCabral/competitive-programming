#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Time: O(n)
    // Space: O(n)
    int singleNumberV1(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            if (st.count(num)) {
                st.erase(num);
            } else {
                st.insert(num);
            }
        }

        return *st.begin();
    }

    // Time: O(n)
    // Space: O(1)
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result = result ^ num;
        }

        return result;
    }
};