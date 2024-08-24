#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> times;
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = make_pair(position[i], speed[i]);
        }
        sort(cars.begin(), cars.end(),
             [](auto& left, auto& right) { return left.first > right.first; });

        double time = (double)(target - cars[0].first) / cars[0].second;
        times.push(time);
        for (int i = 1; i < n; ++i) {
            time = (double)(target - cars[i].first) / cars[i].second;
            if (time > times.top()) {
                times.push(time);
            }
        }

        return times.size();
    }
};

int main() {
    Solution sol;
    int target = 10;
    vector<int> position = {8, 3, 7, 4, 6, 5};
    vector<int> speed = {4, 4, 4, 4, 4, 4};
    int ans = sol.carFleet(target, position, speed);
    cout << ans << endl;
}