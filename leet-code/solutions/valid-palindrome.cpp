#include <bits/stdc++.h>
using namespace std;

bool isNotAlnum(char c) { return isalnum(c) == 0; }
class Solution {
   public:
    bool isPalindrome(string s) {
        for (auto& ch : s) {
            ch = tolower(ch);
        }
        s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());

        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s.at(l++) != s.at(r--)) return false;
        }

        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    bool ans = sol.isPalindrome(s);
    cout << ans << endl;
}