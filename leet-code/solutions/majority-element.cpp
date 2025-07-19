#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int maj = nums[0];

        for (int num : nums) {
            ++count[num];

            if (count[num] > count[maj]) {
                maj = num;
            }
        }

        return maj;
    }
};
