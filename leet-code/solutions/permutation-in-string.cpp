#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    char s1count[26];
    char s2count[26];

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        for (int i = 0; i < s1.size(); ++i) {
            ++s1count[s1[i] - 'a'];
            ++s2count[s2[i] - 'a'];
        }

        for (int i = s1.size(); i < s2.size(); ++i) {
            if (verify(s1)) return true;

            --s2count[s2[i - s1.size()] - 'a'];
            ++s2count[s2[i] - 'a'];
        }

        return verify(s1);
    }

   private:
    bool verify(string& s1) {
        for (char ch : s1) {
            if (s1count[ch - 'a'] != s2count[ch - 'a']) return false;
        }
        return true;
    }
};