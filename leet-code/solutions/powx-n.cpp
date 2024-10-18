#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    double recPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double result = myPow(x, n / 2);

        result *= result;

        if (n % 2 == 1) {
            result *= x;
        }

        return result;
    }

   public:
    double myPow(double x, int n) {
        const int expoent = abs(n);

        double ans = recPow(x, expoent);

        if (n < 0) {
            ans = 1 / ans;
        }

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