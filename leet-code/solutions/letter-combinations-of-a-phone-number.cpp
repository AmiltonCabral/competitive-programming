#include <bits/stdc++.h>
using namespace std;

// Time: O(4^n)
// Space: O(n)
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.size();
        if (n == 0) return result;
        vector<vector<char>> comb = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                     {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                     {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                     {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        string curr = "";

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                result.push_back(curr);
                return;
            }
            for (char word : comb[digits[i] - '2']) {
                curr.push_back(word);
                dfs(i + 1);
                curr.pop_back();
            }
        };

        dfs(0);

        return result;
    }
};