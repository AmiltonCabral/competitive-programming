#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26];
        for (char ch : s) {
            count[ch % 26]++;
        }
        for (char ch : t) {
            count[ch % 26]--;
        }
        for (int num : count) {
            if (num != 0) return false;
        }
        return true;
    }
};