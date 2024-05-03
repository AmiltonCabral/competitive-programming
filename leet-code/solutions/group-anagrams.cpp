#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            anagrams[str_copy].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto pair : anagrams) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};