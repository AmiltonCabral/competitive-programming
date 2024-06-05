#include <bits/stdc++.h>
using namespace std;

// Time: O(n * m), where n = s.len and m = wordDict.len
// Space: O(n)
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; --i) {
            for (string word : wordDict) {
                if (dp[i]) break;
                if (i + word.size() <= s.size() &&
                    word == s.substr(i, word.size())) {
                    dp[i] = dp[i + word.size()];
                }
            }
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    string s = "catsandog";
    vector<string> wordDict = {"cat", "dog", "and", "sand", "og"};
    bool ans = sol.wordBreak(s, wordDict);
    cout << ans << endl;
}
