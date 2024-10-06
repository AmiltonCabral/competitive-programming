#include <vector>
using namespace std;

class Solution {
   private:
    int countBitsByNum(int num) {
        int numBits = 0;

        while (num >= 2) {
            if (num % 2 == 1) {
                ++numBits;
            }

            num /= 2;
        }

        if (num == 1) {
            ++numBits;
        }

        return numBits;
    }

   public:
    // Time: O(n * log n)
    // Space: O(n)
    vector<int> countBitsV1(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; ++i) {
            ans[i] = countBitsByNum(i);
        }

        return ans;
    }

    // Time: O(n)
    // Space: O(n)
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {  // even
                ans[i] = ans[i / 2];
            } else {           // odd
                ans[i] = ans[i - 1] + 1;
            }
        }

        return ans;
    }
};