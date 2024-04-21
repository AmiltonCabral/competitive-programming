#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int m;
    int n;
    int next = 2;
    vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

   public:
    void bt(vector<vector<int>>& grid, pair<int, int> coord) {
        for (pair<int, int> move : moves) {
            int tar_i = coord.first + move.first;
            int tar_j = coord.second + move.second;
            if (tar_i < 0 || tar_j < 0 || tar_i >= m || tar_j >= n) continue;
            if (grid[tar_i][tar_j] == 1) {
                grid[tar_i][tar_j] = grid[coord.first][coord.second];
                bt(grid, {tar_i, tar_j});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> grint(m);
        for (int i = 0; i < m; i++) {
            vector<int> aux(n);
            grint[i] = aux;
            for (int j = 0; j < n; j++) {
                grint[i][j] = grid[i][j] - '0';
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grint[i][j] == 1) {
                    grint[i][j] = next++;
                    bt(grint, {i, j});
                }
            }
        }

        return next - 2;
    }
};

int main() {
    vector<vector<char>> gridx = {
        {'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    vector<vector<char>> gridy = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    vector<vector<char>> gridz = {
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}, {'0', '1', '0', '1', '0'}};

    Solution sol;
    cout << sol.numIslands(gridx) << endl;
}