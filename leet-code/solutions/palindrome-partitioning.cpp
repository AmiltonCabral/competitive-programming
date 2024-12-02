#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        function<void(int, string)> dfs = [&](int i, string ss) {
            if (i == s.size()) {
                if (arr_is_palindrome(part)) {
                    ans.push_back(part);
                }
                return;
            };

            ss += s[i];

            // left
            part.push_back(ss);
            dfs(i + 1, "");
            part.pop_back();

            // right
            if (i < s.size() - 1) {
                dfs(i + 1, ss);
            }
        };

        dfs(0, "");

        return ans;
    }

   private:
    bool is_palindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    bool arr_is_palindrome(vector<string> arr) {
        for (string s : arr) {
            if (!is_palindrome(s)) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}