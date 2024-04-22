#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
            tri.push_back(row);
        }
        return tri;
    }
};

int main() {
    int numRows = 6;
    Solution sol;
    vector<vector<int>> ans = sol.generate(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}