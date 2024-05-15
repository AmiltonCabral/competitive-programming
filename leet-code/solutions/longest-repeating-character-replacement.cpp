#include <bits/stdc++.h>
using namespace std;

class SolutionV1 {
   public:
    int characterReplacementV1(string s, int k) {
        int ans = 1;
        countChar[s[0] - 'A'] = 1;

        int l = 0, r = 0;
        while (r < s.size()) {
            if (verify(k)) {
                ans = max(ans, r - l + 1);
                ++r;
                if (r >= s.size()) break;
                ++countChar[s[r] - 'A'];
            } else {
                --countChar[s[l] - 'A'];
                ++l;
            }
        }

        return ans;
    }

   private:
    int countChar[26] = {};
    bool verify(int k) {
        int mostAppeared = 0;
        int sumWords = 0;
        for (int num : countChar) {
            if (num > 0) {
                mostAppeared = max(mostAppeared, num);
                sumWords += num;
            }
            if (sumWords - mostAppeared > k) {
                return false;
            }
        }
        return true;
    }
};

class SolutionV2 {
   public:
    int characterReplacement(string s, int k) {
        int countChar[26] = {};
        int ans = 0, l = 0;
        int mostAppeared = 0;

        for (int r = 0; r < s.size(); ++r) {
            ++countChar[s[r] - 'A'];
            mostAppeared = max(mostAppeared, countChar[s[r] - 'A']);

            while ((r - l + 1) - mostAppeared > k) {
                --countChar[s[l] - 'A'];
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};