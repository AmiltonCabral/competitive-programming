#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());

        while (!hand.empty()) {
            int prev = hand.front();
            hand.erase(hand.begin());

            for (int i = 0; i < groupSize - 1; ++i) {
                auto it = lower_bound(hand.begin(), hand.end(), prev + 1);
                int index = distance(hand.begin(), it);

                if (index < hand.size() && prev + 1 == hand.at(index)) {
                    ++prev;
                    hand.erase(hand.begin() + index);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> hand = {1, 1, 2, 2, 3, 3};
    int groupSize = 2;
    bool ans = sol.isNStraightHand(hand, groupSize);
    cout << ans << endl;
}
