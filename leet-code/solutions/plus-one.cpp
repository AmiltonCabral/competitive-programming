#include <bits/stdc++.h>
using namespace std;

// Time: O(n); Space: O(n)
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int up = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            int upAux = (digits[i] + up) / 10;
            digits[i] = (digits[i] + up) % 10;
            up = upAux;
        }

        vector<int> ans(up ? digits.size() : digits.size() - 1);

        if (up > 0) ans.push_back(up);

        for (int num : digits) {
            ans.push_back(num);
        }

        return ans;
    }
};

// Time: O(n); Space: O(2n) = O(n)
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> stk;
        int up = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            stk.push((digits[i] + up) % 10);
            up = (digits[i] + up) / 10;
        }

        vector<int> ans;

        if (up > 0) ans.push_back(up);

        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};