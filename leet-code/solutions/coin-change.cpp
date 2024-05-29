#include <bits/stdc++.h>
using namespace std;

// BFS approach
class SolutionV1 {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        unordered_set<int> visited;
        queue<pair<int, int>> qu;
        qu.push({0, 1});

        while (!qu.empty()) {
            int sum = qu.front().first;
            int i = qu.front().second;
            qu.pop();

            for (int coin : coins) {
                if (!visited.count(coin + sum)) {
                    if (coin + sum == amount) {
                        return i;
                    }

                    if (coin + sum < amount) {
                        visited.insert(coin + sum);
                        qu.push({coin + sum, i + 1});
                    }
                }
            }
        }

        return -1;
    }
};

// Dynamic Programming approach
// Sort is fast here because: coins.size() <= 12
// Time: O(amount)
// Space: O(amount)
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin > i) {
                    break;
                }

                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {474, 83, 404, 3};
    int amount = 264;
    int ans = sol.coinChange(coins, amount);
    cout << ans << endl;
}
