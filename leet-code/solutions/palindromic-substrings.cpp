#include <bits/stdc++.h>
using namespace std;

// Time: O(n^3)
// Space: O(1)
// Approach: Generate all substrings and verify if is palindrome
class SolutionV1 {
   public:
    int countSubstrings(string s) {
        int count = 0;

        for (int l = 0; l < s.size(); ++l) {
            for (int r = l; r < s.size(); ++r) {
                bool isPal = true;
                int ll = l;
                int rr = r;
                while (ll < rr) {
                    if (s.at(ll) != s.at(rr)) {
                        isPal = false;
                        break;
                    }
                    ++ll;
                    --rr;
                }
                if (isPal) {
                    ++count;
                }
            }
        }

        return count;
    }
};

// Time: O(n^2)
// Space: O(1)
// Approach: For each char in string, expand until substring no more palindrome
class Solution {
   public:
    int countSubstrings(string s) {
        int count = 0;

        auto check = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s.at(l) == s.at(r)) {
                --l;
                ++r;
                ++count;
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            check(i, i);      // odd
            check(i, i + 1);  // even
        }

        return count;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    int ans = sol.countSubstrings(s);
    cout << ans << endl;
}