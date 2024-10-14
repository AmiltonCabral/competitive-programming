#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        if (n == 1) return true;

        // Explanation to n == 4:
        // (2 => 2^2 = 4) and (20 => 2^2 + 0^2 = 4)
        if (n == 4) return false;

        int nextN = 0;

        while (n > 0) {
            nextN += pow((n % 10), 2);
            n /= 10;
        }

        return isHappy(nextN);
    }
};
