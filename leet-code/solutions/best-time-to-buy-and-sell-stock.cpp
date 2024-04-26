#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> smaller(prices.size());
        vector<int> biggers(prices.size());

        smaller[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            smaller[i] = min(smaller[i - 1], prices[i]);
        }

        biggers[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            biggers[i] = max(biggers[i + 1], prices[i]);
        }

        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, biggers[i] - smaller[i]);
        }
        return ans;
    }
};

// prices = [7,1,5,3,6,4]
//          [7,1,1,1,1,1]
//          [7,6,6,6,6,4]