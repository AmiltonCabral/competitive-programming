#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rptdCol;
        unordered_set<char> rptdRow;
        unordered_set<char> rptdSquare[3][3];

        for (int i = 0; i < 9; i++) {
            rptdCol.clear();
            rptdRow.clear();

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rptdRow.count(board[i][j]) ||
                        rptdSquare[i / 3][j / 3].count(board[i][j])) {
                        return false;
                    }
                    rptdRow.insert(board[i][j]);
                    rptdSquare[i / 3][j / 3].insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (rptdCol.count(board[j][i])) {
                        return false;
                    }
                    rptdCol.insert(board[j][i]);
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

    bool ans = sol.isValidSudoku(board);
    cout << ans << endl;
}