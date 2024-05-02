#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int m, n, target;

    int bsRow(vector<vector<int>>& mt, int l, int r) {
        int mid = (l + r) / 2;
        if (target >= mt[mid][0] && target <= mt[mid][n]) {
            return mid;
        }
        if (l >= r) {
            return -1;
        }
        if (target < mt[mid][0]) {
            return bsRow(mt, l, mid - 1);
        }
        return bsRow(mt, mid + 1, r);
    }

    bool bsCol(vector<vector<int>>& mt, int row, int l, int r) {
        int mid = (l + r) / 2;
        if (mt[row][mid] == target) {
            return true;
        }
        if (l >= r) {
            return false;
        }
        if (target < mt[row][mid]) {
            return bsCol(mt, row, l, mid - 1);
        }
        return bsCol(mt, row, mid + 1, r);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        this->target = target;
        m = matrix.size() - 1;
        n = matrix[0].size() - 1;
        if (target < matrix[0][0] || target > matrix[m][n]) {
            return false;
        }
        int row = bsRow(matrix, 0, m);
        if (row == -1) {
            return false;
        }
        return bsCol(matrix, row, 0, n);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    int ans = sol.searchMatrix(matrix, target);
    cout << ans << endl;
}