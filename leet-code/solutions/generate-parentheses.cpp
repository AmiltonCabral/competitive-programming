#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canContinue(string s, int n) {
        int openCount = 0;
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(') {
                stk.push(ch);
                openCount++;
            } else if (stk.empty()) {
                return false;
            } else {
                stk.pop();
            }
        }
        return openCount <= n;
    }

    vector<string> bt(int& n, string comb, vector<string>& ans) {
        if (canContinue(comb, n)) {
            if (comb.size() == n * 2) {
                ans.push_back(comb);
            } else {
                bt(n, comb + '(', ans);
                bt(n, comb + ')', ans);
            }
        }

        return ans;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans = bt(n, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);
    cout << endl;
}