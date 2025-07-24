#include <functional>
using namespace std;

class Solution {
   public:
    // Time = O(x)
    int mySqrt1(int x) {
        long long prev = 0;

        for (long long i = 0; i * i <= x; ++i) {
            if (i * i == x) return i;
            prev = i;
        }

        return prev;
    }

    // Time = O(log x)
    int mySqrt(int x) {
        int ans;
        int l = 0;
        int r = x;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid == x) return mid;
            if (mid * mid < x) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};