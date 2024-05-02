#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minutes = 0;
    array<int, 4> xMove = {-1, 0, 1, 0};
    array<int, 4> yMove = {0, -1, 0, 1};

    bool validMove(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x,
                   int y) {
        if (x < 0 || y < 0 || x >= vis.size() || y >= vis[0].size() ||
            vis[x][y] || grid[x][y] != 1) {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& extQueue,
             vector<vector<bool>>& vis) {
        while (!extQueue.empty()) {
            queue<pair<int, int>> q;
            while (!extQueue.empty()) {
                q.push(extQueue.front());
                extQueue.pop();
            }

            int modified = false;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + xMove[i];
                    int ny = y + yMove[i];
                    if (validMove(grid, vis, nx, ny)) {
                        extQueue.push({nx, ny});
                        vis[nx][ny] = true;
                        grid[nx][ny] = 2;
                        modified = true;
                    }
                }
            }

            if (modified)
                minutes++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        bfs(grid, q, vis);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};
