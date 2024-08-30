#include <bits/stdc++.h>
using namespace std;

// Time:  O(m * p), where m = max(pile) and p = pile.size()
// Space: O(1)
class SolutionV1 {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        while (true) {
            long long times = 0;
            for (int pile : piles) {
                int curr = pile / k;
                if (pile % k > 0) ++curr;
                times += curr;
            }

            if (times <= h) break;
            ++k;
        }

        return k;
    }
};

// Time:  O(log(m) * p), where m = max(pile) and p = pile.size
// Space: O(1)
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        auto idxMaxEl = max_element(piles.begin(), piles.end());
        int r = *idxMaxEl;
        int k = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            long long times = 0;

            for (int pile : piles) {
                int curr = pile / mid;
                if (pile % mid > 0) ++curr;
                times += curr;
            }

            if (times <= h) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};
