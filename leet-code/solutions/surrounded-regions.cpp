#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void visit(vector<vector<char>>& board, pair<int, int> coord,
               vector<vector<bool>>& visited) {
        if (visited[coord.first][coord.second]) return;
        visited[coord.first][coord.second] = true;

        for (pair<int, int> move : moves) {
            int x = coord.first + move.first;
            int y = coord.second + move.second;
            if (x > 0 && x < board.size() - 1 && y > 0 &&
                y < board[0].size() - 1 && board[x][y] == 'O') {
                visit(board, {x, y}, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() <= 2 || board[0].size() <= 2) return;

        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size()));

        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') visit(board, {i, 0}, visited);
            if (board[i].back() == 'O')
                visit(board, {i, board[0].size() - 1}, visited);
        }

        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 'O') visit(board, {0, j}, visited);
            if (board.back()[j] == 'O')
                visit(board, {board.size() - 1, j}, visited);
        }

        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[0].size() - 1; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'X', 'O', 'X', 'X'},
                                  {'O', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'O'},
                                  {'O', 'X', 'O', 'X'}};
    sol.solve(board);
    cout << endl;
}