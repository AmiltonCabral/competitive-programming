#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0;
        return dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) +
               dfs(grid, i, j - 1) + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int islandArea = dfs(grid, i, j);
                    maxArea = max(islandArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};