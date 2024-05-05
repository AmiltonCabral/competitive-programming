#include <bits/stdc++.h>
using namespace std;
typedef pair<float, int> fipair;

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<fipair, vector<fipair>, greater<fipair>> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push({sqrt(points[i][0] * points[i][0] +
                          points[i][1] * points[i][1]),
                     i});
        }

        vector<vector<int>> ans(k);
        while (k--) {
            ans[k] = points[pq.top().second];
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{-5, 4}, {-6, -5}, {4, 6}};
    int k;
    vector<vector<int>> ans = sol.kClosest(points, k);
    cout << endl;
}

// 6.4   |   7.8   |   7.2