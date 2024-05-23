#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string ans = "";

        for (int i = 0; i < s.size(); ++i) {
            // even
            int j = 0;
            while (i - j - 1 >= 0 && i + j + 1 < s.size() &&
                   s[i - j - 1] == s[i + j + 1]) {
                ++j;
            }
            if (j + j + 1 > maxLen) {
                ans = s.substr(i - j, j + j + 1);
                maxLen = ans.size();
            }

            // odd
            j = 0;
            if (i + 1 >= s.size() || s.at(i) != s.at(i + 1)) continue;
            while (i - j - 1 >= 0 && i + j + 2 < s.size() &&
                   s[i - j - 1] == s[i + j + 2]) {
                ++j;
            }
            if (j + j + 2 > maxLen) {
                ans = s.substr(i - j, j + j + 2);
                maxLen = ans.size();
            }
        }

        return ans;
    }
};

signed main() {
    Solution sol;
    string s;
    cin >> s;
    string ans = sol.longestPalindrome(s);
    cout << ans << '\n';
}