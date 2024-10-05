class Solution {
   public:
    int hammingWeight(int n) {
        int response = 0;

        while (n >= 2) {
            if (n % 2 == 1) {
                ++response;
            }

            n = n / 2;
        }

        if (n == 1) {
            ++response;
        }

        return response;
    }
};