#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string s;
    unordered_map<string, int> cache;

    int numDecodings(string s) {
        this->s = s;

        return dfs(0, "");
    }

    int dfs(int i, string curr) {
        if (i >= s.size()) {
            return 0;
        };

        curr += s[i];

        if (curr == "0" || curr.size() >= 3 || stoi(curr) > 26) return 0;

        if (i == s.size() - 1) {
            return 1;
        }

        string keyL = to_string(i + 1) + '%';
        string keyR = keyL + curr;

        if (!cache.count(keyL)) {
            cache[keyL] = dfs(i + 1, "");
        }
        if (!cache.count(keyR)) {
            cache[keyR] = dfs(i + 1, curr);
        }

        return cache[keyL] + cache[keyR];
    };
};

int main() {
    Solution sol;
    string s = "11106";
    int ans = sol.numDecodings(s);
    cout << ans << endl;
}