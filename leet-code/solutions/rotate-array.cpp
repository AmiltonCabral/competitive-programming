#include <functional>
#include <vector>
using namespace std;

class Solution {
   public:
    // Time O(n), Space O(n)
    void rotateN(vector<int>& nums, int k) {
        // (index + k) % nums.size()
        vector<int> numsRotated(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            numsRotated[(i + k) % nums.size()] = nums[i];
        }

        nums = numsRotated;
    }

    // Time O(n), Space O(1)
    void rotate(vector<int>& nums, int k) {
        if (k % nums.size() == 0) return;

        function<void(int, int)> reverse = [&](int l, int r) {
            while (l < r) {
                int aux = nums[l];
                nums[l] = nums[r];
                nums[r] = aux;
                ++l;
                --r;
            }
        };

        // reverse all
        reverse(0, nums.size() - 1);

        // reverse first k elements
        reverse(0, (k - 1) % nums.size());

        // reverse after the k element
        reverse(k % nums.size(), nums.size() - 1);
    }
};
