#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        unordered_set<char> tset;
        for (char ch : t) {
            ++target[ch];
            tset.insert(ch);
        }
        unordered_map<char, int> curr;

        string ans = "";
        int better = s.size();
        int miss = target.size();
        int l = 0, r = -1, size = 0;

        while (true) {
            // Left
            char ch = s[l];
            while (!tset.count(ch) || curr[ch] - 1 >= target[ch]) {
                if (tset.count(ch)) {
                    --curr[ch];
                }

                ++l;
                if (l >= s.size()) return ans;

                --size;
                ch = s[l];
            }

            // Check if found a better solution
            if (miss == 0 && size <= better) {
                better = size;
                ans = s.substr(l, size);
            }

            // Right
            ++r;
            ++size;
            if (r >= s.size()) break;
            ch = s[r];
            if (tset.count(ch)) {
                ++curr[ch];
                if (curr[ch] == target[ch]) {
                    --miss;
                }
            }

            // Check if found a better solution
            if (miss == 0 && size <= better) {
                better = size;
                ans = s.substr(l, size);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "a";
    string t = "aa";
    string ans = sol.minWindow(s, t);
    cout << ans << endl;
}