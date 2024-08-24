#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

        double ans = x;

        if (n < 0) {
            n *= -1;
            x = 1 / x;
        }

        int i = 1;
        while (i + i < n) {
            ans *= ans;
            i += i;
        }

        while (i < n) {
            ans *= x;
            ++i;
        }

        // while (n--) {
        //     ans *= x;
        // }

        return ans;
    }
};

int main() {
    Solution sol;
    double x = 2.00000;
    int n = 10;
    double ans = sol.myPow(x, n);

    cout << ans << endl;
}