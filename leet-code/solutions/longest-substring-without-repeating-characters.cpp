#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> wset;
        int l = 0, r = 0, longest = 0, locallen = 0;
        while (r < s.size()) {
            if (wset.count(s[r])) {
                while (wset.count(s[r])) {
                    wset.erase(s[l]);
                    locallen--;
                    l++;
                }
            } else {
                wset.insert(s[r]);
                locallen++;
                r++;
                longest = max(longest, locallen);
            }
        }
        return longest;
    }
};